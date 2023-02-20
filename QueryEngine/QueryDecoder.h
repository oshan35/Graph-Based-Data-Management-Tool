#include<iostream>
#include<vector>
#include <sstream>
#include <algorithm>
#include "Query.h"
#include "WhereQuery.h"
#include "QueryService.h"

using namespace std;


class QueryDecoder{
    public:
        
    string queryType(string query){
        vector<string> keyWords = {"select","from","where","relate", "connections"};
        vector<string> queryWordList = QueryService::split(query,' '); // [SELECT, CoustemerName, FROM, Customers, WHERE, Countrty='Mexico']
        //[012, 013, 014]

        string queryCode = "";

        
        for (int i = 0; i < queryWordList.size(); i++)
        {   
            auto it = find(keyWords.begin(), keyWords.end(), queryWordList[i]);
            if(it != keyWords.end()){
                //queryCode = queryWordList[i]; // FROM
                int index = distance(keyWords.begin(), it); //1
                queryCode += std::to_string(index); //012

            }
            
        }
        //cout<<"Query Code: "<<queryCode<<endl;
        return queryCode;
        
    }

    // void queryDecoder(string queryCode, string query){
    //     Query* queryObj;
    //    if (queryCode == "012")
    //    {
    //         queryObj = new WhereQuery(query);
    //         queryObj->toString();
        
            
    //    }
    //    //return queryObj;
    
    // }

    Query* queryResult(string queryCode, string query){
        Query* queryObj;
        if (queryCode == "012")
        {
                queryObj = new WhereQuery(queryCode,query);
                queryObj->toString();   
        }else if(queryCode == "013"){
            queryObj;
        }

        return queryObj;
    }

    Query* createQuery(string query){
        string queryType = QueryDecoder::queryType(query);

        Query* result= QueryDecoder::queryResult(queryType,query);
        return result;
    }

};

