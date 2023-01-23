#include<iostream>
#include<vector>
#include<map>
#include <sstream>
#include <algorithm>

using namespace std;

class Query{
    string queryStr;

    map<string,vector<string>> queryParameters;

    vector<string> FROM;
    vector<string> SELECT;
    vector<string> WHERE; // col = data

    vector<string> MATCH; 

    vector<string> INCONNECTION;
    vector<string> OUTCONNECTION;
    vector<string> ALLCONNECTION;

    string queryCode;


    Query(string query){
        queryStr = query;
    }

    
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

            /*
        SELECT CoustemerName
        FROM Customers
        WHERE Country='Mexico';
        */

    void decodeQuery(string query){
        // SELECT name, age FROM studentDetails WHERE age = 22
        vector<string> keyWords = {"SELECT","FROM","WHERE","MATCH", "INCONNECTION", "OUTCONNECTION", "ALLCONNECTIONS"};
        vector<string> queryWordList = split(query,' '); // [SELECT, CoustemerName, FROM, Customers, WHERE, Countrty='Mexico']

        string currentCommnd;

        
        for (int i = 0; i < queryWordList.size(); i++)
        {   
            auto it = find(keyWords.begin(), keyWords.end(), queryWordList[i]);
            if(it != keyWords.end()){
                currentCommnd = queryWordList[i]; // FROM
                int index = distance(keyWords.begin(), it); //1
                query += std::to_string(index); //012

            }else{
                if (currentCommnd == "SELECT")
                {
                    queryParameters["SELECT"].push_back(queryWordList[i])
                    // SELECT.push_back(queryWordList[i]);
                }else if(currentCommnd =="FROM"){
                    FROM = queryWordList[i];
                }else if(currentCommnd == "WHERE"){
                    WHERE.push_back(queryWordList[i]);
                }else if(currentCommnd == "MATCH"){
                    MATCH.push_back(queryWordList[i]);
                }else if (currentCommnd == "INCONNECTION")
                {
                    INCONNECTION.push_back(queryWordList[i]);
                }else if (currentCommnd == "OUTCONNECTION")
                {
                    OUTCONNECTION.push_back(queryWordList[i]);
                }else if (currentCommnd == "ALLCONNECTION")
                {
                    ALLCONNECTION.push_back(queryWordList[i]);
                }
            }
            
        }
        
    }

};