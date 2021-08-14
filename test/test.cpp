//
// Created by Kyle Gendreau on 7/26/21.
//

#include <string>
#include <iostream>
#include <queue>
#include "../include/DeAccenter.h"

void run_default_tests();

void print_message(const std::string& s);

//region //STANDARD FUNCTION DECLARATION

//region //CONSTRUCTOR TESTS
void constructor_default_tests();
    std::string constructor_default_hashFilled();

//endregion


//region //ISACCENTED TESTS
void isAccented_default_tests();
    std::string isAccented_default_properReturn(std::string s, bool isAccented);
    std::string isAccented_default_properReturnCalls();

//endregion


//region //CONTAINSACCENT TESTS
void containsAccent_default_tests();
    std::string containsAccent_default_properReturn(std::string s, bool hasAccent);
    std::string containsAccent_default_properReturnCalls();

//endregion


//region //REMOVEACCENT TESTS
void removeAccent_defualt_tests();
    std::string removeAccent_default_properReturn(std::string og, std::string ret);
    std::string removeAccent_default_properReturnCalls();

//endregion


//region //REMOVEALLACCENTS TESTS
void removeAllAccents_default_tests();
    std::string removeAllAccents_default_properReturn(std::string og, std::string ret);
    std::string removeAllAccents_default_properReturnCalls();

//endregion

//endregion

int main() {

    std::cout << "DEACCENTER TEST(S):\n";
    run_default_tests();

    return 0;
}

void run_default_tests() {
    constructor_default_tests();
    isAccented_default_tests();
    containsAccent_default_tests();
    removeAccent_defualt_tests();
    removeAllAccents_default_tests();
}

void print_message(const std::string& s) {
    if (s.empty()) {
        std::cout << "PASS" << std::endl;
    }
    else {
        std::cout << "FAIL" << std::endl << s;
    }
}

//region //FUNCTION DEFINITIONS

void constructor_default_tests() {
    std::cout << "default constructor test(s): ";
    std::string s;

    s += constructor_default_hashFilled();

    print_message(s);
}
std::string constructor_default_hashFilled() {
    std::string out("\t- hash properly filled: ");
    try {
        DeAccenter deac;
        bool val(true), masterVal(true);
        std::queue<std::string> que;

        std::ifstream input("../src/map.csv");
        std::string line, token, accented;
        int cnt(0);

        while (std::getline(input,line,'\n')) {
            std::stringstream ss(line);
            while (std::getline(ss,token,'\t')) {
                if (cnt % 2 == 0) {
                    accented = token;
                    val = deac.isAccented(accented,0);
                }
                else if (cnt % 2 == 1) {
                    val = token == deac.removeAccent(accented,0);
                }
                ++cnt;
            }
            if (!val) {
                que.push(accented);
                masterVal = false;
                val = true;
            }
        }

        input.close();

        token.clear();
        while (!que.empty()) {
            token += "\t" + que.front() + "\n";
            que.pop();
        }

        return (!masterVal) ? out + "fail\n" + token : "";
    }
    catch(...) {
        return out + "UNKNOWN ERROR\n";
    }
}

void isAccented_default_tests() {
    std::cout << "default isAccented test(s): ";
    std::string s;

    s += isAccented_default_properReturnCalls();

    print_message(s);
}
std::string isAccented_default_properReturn(std::string s, bool isAccented) {
    std::string out("\t- proper return: " + s + " returns ");
    try {
        DeAccenter deac;
        bool val = deac.isAccented(s,0) == isAccented;

        return (val) ? "" : out + std::to_string(!isAccented) + "\n";
    }
    catch(...) {
        return out + "UNKNOWN ERROR\n";
    }
}
std::string isAccented_default_properReturnCalls() {
    std::string out;

    out += isAccented_default_properReturn("å",true);
    out += isAccented_default_properReturn("a",false);
    out += isAccented_default_properReturn("л",false);
    out += isAccented_default_properReturn("诶",false);
    out += isAccented_default_properReturn("Ä",true);

    return out;
}

void containsAccent_default_tests() {
    std::cout << "default containsAccent test(s): ";
    std::string s;

    s += containsAccent_default_properReturnCalls();

    print_message(s);
}
std::string containsAccent_default_properReturn(std::string s, bool hasAccent) {
    std::string out("\t- proper return: " + s + " returns ");
    try {
        DeAccenter deac;
        bool val = deac.containsAccent(s) == hasAccent;

        return (val) ? "" : out + std::to_string(!hasAccent) + "\n";
    }
    catch(...) {
        return out + "UNKNOWN ERROR\n";
    }
}
std::string containsAccent_default_properReturnCalls() {
    std::string out;

    out += containsAccent_default_properReturn("å",true);
    out += containsAccent_default_properReturn("så",true);
    out += containsAccent_default_properReturn("ås",true);
    out += containsAccent_default_properReturn("sås",true);
    out += containsAccent_default_properReturn("ss",false);
    out += containsAccent_default_properReturn("",false);
    out += containsAccent_default_properReturn("s",false);

    return out;
}

void removeAccent_defualt_tests() {
    std::cout << "default removeAccent test(s): ";
    std::string s;

    s += removeAccent_default_properReturnCalls();

    print_message(s);
}
std::string removeAccent_default_properReturn(std::string og, std::string ret) {
    std::string out("\t- proper return: " + og + " returns ");
    try {
        DeAccenter deac;
        bool val = deac.removeAccent(og,0) == ret;

        return (val) ? "" : out + deac.removeAccent(og,0) + "\n";
    }
    catch(...) {
        return out + "UNKNOWN ERROR\n";
    }
}
std::string removeAccent_default_properReturnCalls() {
    std::string out;

    out += removeAccent_default_properReturn("å","a");
    out += removeAccent_default_properReturn("a","a");
    out += removeAccent_default_properReturn("л","л");
    out += removeAccent_default_properReturn("诶","诶");
    out += removeAccent_default_properReturn("Ä","A");
    out += removeAccent_default_properReturn("","");
    out += removeAccent_default_properReturn(" Ä"," Ä");
    out += removeAccent_default_properReturn("Ä ","A ");

    return out;
}

void removeAllAccents_default_tests() {
    std::cout << "default removeAllAccents test(s): ";
    std::string s;

    s += removeAllAccents_default_properReturnCalls();

    print_message(s);
}
std::string removeAllAccents_default_properReturn(std::string og, std::string ret) {
    std::string out("\t- proper return: " + og + " returns ");
    try {
        DeAccenter deac;
        bool val = deac.removeAllAccents(og) == ret;

        return (val) ? "" : out + deac.removeAllAccents(og) + "\n";
    }
    catch(...) {
        return out + "UNKNOWN ERROR\n";
    }
}
std::string removeAllAccents_default_properReturnCalls() {
    std::string out;

    out += removeAllAccents_default_properReturn("å","a");
    out += removeAllAccents_default_properReturn("a","a");
    out += removeAllAccents_default_properReturn("л","л");
    out += removeAllAccents_default_properReturn("诶","诶");
    out += removeAllAccents_default_properReturn("Ä","A");
    out += removeAllAccents_default_properReturn("","");
    out += removeAllAccents_default_properReturn(" Ä"," A");
    out += removeAllAccents_default_properReturn("Ä ","A ");

    out += removeAllAccents_default_properReturn("ÄoutĪ","AoutI");
    out += removeAllAccents_default_properReturn("àèîôû","aeiou");
    out += removeAllAccents_default_properReturn("aèîôû","aeiou");
    out += removeAllAccents_default_properReturn("àeîôû","aeiou");
    out += removeAllAccents_default_properReturn("àèiôû","aeiou");
    out += removeAllAccents_default_properReturn("àèîoû","aeiou");
    out += removeAllAccents_default_properReturn("àèîôu","aeiou");
    out += removeAllAccents_default_properReturn("àeioû","aeiou");

    return out;
}

//endregion
