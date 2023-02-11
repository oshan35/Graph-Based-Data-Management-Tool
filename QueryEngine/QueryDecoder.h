#include<iostream>
#include<vector>
#include <sstream>
#include <algorithm>
#include "Query.h"
#include "WhereQuery.h"
#include "QueryService.h"

using namespace std;



string queryType(string query){
    vector<string> keyWords = {"SELECT","FROM","WHERE","MATCH", "CONNECTIONS"};
    vector<string> queryWordList = QueryService::split(query,' '); // [SELECT, CoustemerName, FROM, Customers, WHERE, Countrty='Mexico']
    //[012, 013, 014]

    string queryCode;

    
    for (int i = 0; i < queryWordList.size(); i++)
    {   
        auto it = find(keyWords.begin(), keyWords.end(), queryWordList[i]);
        if(it != keyWords.end()){
            queryCode = queryWordList[i]; // FROM
            int index = distance(keyWords.begin(), it); //1
            query += std::to_string(index); //012

        }
        
    }
    return queryCode;
    
}

void queryDecoder(string queryCode, string query){
   if (queryCode == "012")
   {
        Query* whereQuery = new WhereQuery(query);
    
   }
   
}
