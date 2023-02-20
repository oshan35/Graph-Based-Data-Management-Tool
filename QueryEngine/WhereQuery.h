#include<iostream>
#include<vector>
#include<map>
#include <sstream>
// #include "Query.h"
#include "QueryService.h"

using namespace std;

class WhereQuery:public Query{

    public:
       
    vector<string> match;
    string colName;
    string data;

    WhereQuery(string queryId,string queryString): Query(queryId){
        queryDecoder(queryString);
        

    }

    void toString() override{
        cout<<"select "<<select[0]<<" from "<<from<<" where "<<colName<<"="<<data<<endl;
    }



    void queryDecoder(string queryString){
        
        vector<string> queryWordList = QueryService::split(queryString,' ');
        bool _para_mode = false;
        string current_para;
        int i = 0; 
        while (i < queryWordList.size())
        {
           if (queryWordList[i]=="select")
           {
                //vector<string> selectedCols  = QueryService::split(queryWordList[i+1],',');
                select = queryWordList[i+1];
                i = i+2;
                
           }else if (queryWordList[i]=="from")
           {
                from = queryWordList[i+1];
                i = i +2;

           }else
           {

                char _delimiter = QueryService::findCondtion(queryWordList[i+1]);
                
                vector<string> paraList = QueryService::split(queryWordList[i+1],_delimiter);
                colName = paraList[0];
                data = paraList[1];
                i = i +2;

                    
           }
           
           
           
        }
        



    }







};