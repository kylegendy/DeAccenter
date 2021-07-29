//
// Created by Kyle Gendreau on 7/28/21.
//

#ifndef DEACCENTER_DEACCENTER_CPP
#define DEACCENTER_DEACCENTER_CPP

#include "../include/DeAccenter.h"

DeAccenter::DeAccenter() : hash() {

    std::ifstream input("../src/map.csv");
    std::string line, token, accented;
    int cnt(0);

    while (std::getline(input,line,'\n')) {
        std::stringstream ss(line);
        while (std::getline(ss,token,'\t')) {
            if (cnt % 2 == 0) {
                accented = token;
            }
            else if (cnt % 2 == 1) {
                hash.emplace(accented,token.at(0));
            }
            ++cnt;
        }
    }

    input.close();
}

bool DeAccenter::isAccented(const std::string &s, uint32_t index) const {
    return hash.contains(s.substr(index,2));
}

bool DeAccenter::containsAccent(const std::string &s) const {
    int32_t len(s.size() - 1);
    for (int32_t i(0); i < len; ++i) { // iterate through entire str
        if (isAccented(s,i))
            return true;
    }
    return false;
}

std::string DeAccenter::removeAccent(const std::string &s, uint32_t index) const {
    auto iter(hash.find(s.substr(index,2))); // look for key
    if (iter != hash.end()) {
        std::string v(s);
        v.replace(index,2,std::string() += iter->second);
        return v;
    }
    return s;
}

std::string DeAccenter::removeAllAccents(const std::string &s) const {
    std::string deaccStr(s); // create a copy of the const str
    for (int32_t i(0); i < int32_t(deaccStr.size()) - 1; ++i) { // iterate through entire str
        deaccStr = removeAccent(deaccStr, i); // replace
    }
    return deaccStr; // return output
}

#endif //DEACCENTER_DEACCENTER_CPP