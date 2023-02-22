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

namespace QueryService{
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

    char findCondtion(string line){
        std::array<std::string, 3> elements = {"=", ">", "<"};

        for (const auto& element : elements) {
            if (line.find(element) != std::string::npos) {
                if (element == "=")
                {
                    return '=';
                }else if (element==">")
                {
                    return '>';
                }else{
                    return '<';
                }
                
            }
        }
        return ' ';

    }

    const char* stringToCharArray(const std::string& input) {
        return input.empty() ? nullptr : &input[0];
    }

    char convert(string s){
        if (s == "=")
        {
            return '=';
        }else if (s==">")
        {
            return '>';
        }else{
            return '<';
        }
        
        
    }

    void replaceUnderscoresWithSpaces(std::string& str) {
        for (std::size_t i = 0; i < str.size(); ++i) {
            if (str[i] == '_') {
                str[i] = ' ';
            }
        }
    }

    void printVector(const std::vector<std::string>& vec) {
        cout<<"vector: ";
        for (const auto& item : vec) {
            std::cout << item << std::endl;
        }
    
    }
}

#endif 