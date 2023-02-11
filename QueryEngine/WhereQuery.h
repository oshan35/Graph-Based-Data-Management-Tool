#include<iostream>
#include<vector>
#include<map>
#include <sstream>
#include "Query.h"
#include "QueryService.h"

using namespace std;

class WhereQuery:public Query{

    public:

    WhereQuery(string queryString){
        queryDecoder(queryString);

    }

    private:
    vector<string> match;
    string colName;
    string data;

    void queryDecoder(string queryString){
        
        vector<string> queryWordList = QueryService::split(queryString,' ');
        bool _para_mode = false;
        string current_para =NULL;

        for (int i = 0; i < queryWordList.size(); i++)
        {
           if (queryWordList[i]=="select" || current_para == "select")
           {
                current_para = "select";
                if (queryWordList[i]!="select")
                {
                    select.push_back(queryWordList[i]);
                }
                
           }else if (queryWordList[i]=="from" || current_para == "from")
           {
                current_para = "from";
                if (queryWordList[i]!="from")
                {
                    from =  queryWordList[i];
                }
           }else if (queryWordList[i]=="connections" || current_para == "connections")
           {
                current_para = "connections";
                if (queryWordList[i]!="connections");
                {
                    char _delimiter = QueryService::findCondtion(queryWordList[i]);
                   
                    vector<string> paraList = QueryService::split(queryWordList[i],_delimiter);
                    colName = paraList[0];
                    data = paraList[1];

                }
           }
           
           
           
        }
        



    }







};