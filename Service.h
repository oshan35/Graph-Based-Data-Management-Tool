#ifndef MY_HEADER_FILE_H
#define MY_HEADER_FILE_H

#include<iostream>
#include<vector>
#include <sstream>
#include <algorithm>
// #include "Query.h"
#include <array>
#include <string>


using namespace std;

namespace Service{
    std::vector<std::string> split(const std::string& s, char delimiter)
    {
        std::vector<std::string> tokens;
        std::string token;
        std::istringstream token_stream(s);
        while (std::getline(token_stream, token, delimiter))
        {
            tokens.push_back(token);
        }
        return tokens;
    }


 

    bool containsSubstring(const std::string& mainString, const std::string& substring) {
        return mainString.find(substring) != std::string::npos;
    }


}

#endif 