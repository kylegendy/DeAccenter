//
// Created by Kyle Gendreau on 7/26/21.
//

#ifndef DEACCENTER_DEACCENTER_H
#define DEACCENTER_DEACCENTER_H

#include <unordered_map>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

class DeAccenter {
public:

    // def ctor
    explicit DeAccenter();

    // no copy ctor
    explicit DeAccenter(const DeAccenter& rhs) = delete;

    // dtor
    ~DeAccenter() = default;

    // no assignment
    DeAccenter& operator=(const DeAccenter& rhs) = delete;

    /**
     * determines if a symbol is a germanic letter with an accent at index, capital or lowercase
     * @param string - any string
     * @param index - index being checked within string
     * @return true if a germanic letter with an accent at index, else false
     */
    bool isAccented(const std::string& string, uint32_t index) const;

    /**
     * determines if a string contains a germanic symbol with an accent, capital or lowercase
     * @param string - any string
     * @return true if the string contains ANY germanic symbol with an accent, else false
     */
    bool containsAccent(const std::string& string) const;

    /**
     * if the given parameter is a germanic character with an accent, it will return the germanic character without an
     * accent, capital or lowercase
     * @param string - any string
     * @param index - index being checked within string
     * @return the same string without an accent at index if germanic, else the same character
     */
    std::string removeAccent(const std::string& string, uint32_t index) const;

    /**
     * replaces any germanic symbols with accents with their base, unaccented characters
     * @param string - any given string
     * @return the same string without an accents, else the same string
     */
    std::string removeAllAccents(const std::string& string) const;

private:

    // container that maps all germanic symbols with accents to the same germanic chars without accents
    std::unordered_map<std::string,char32_t> hash;

};

#endif //DEACCENTER_DEACCENTER_H
