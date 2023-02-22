#include<iostream>
#include<vector>
#include<map>
#include <sstream>
//#include "Query.h"
#include "QueryService.h"

using namespace std;

class RelationQuery:public Query{

    public:
       
    string col1;
    string col2;
    string data1;
    string data2;

    RelationQuery(string queryId,string queryString): Query(queryId){
        queryDecoder(queryString);
        

    }

    void toString() override{
        cout<<"select "<<select[0]<<" from "<<from<<" relate "<<col1<<"="<<data1<<" "<<col2<<"="<<data2<<endl;
    }

    void queryDecoder(string queryString){
        
        vector<string> queryWordList = QueryService::split(queryString,' ');
        //QueryService::printVector(queryWordList);
        bool _para_mode = false;
        string current_para;
        int i = 0; 
        while (i < queryWordList.size())
        {
           if (queryWordList[i]=="select")
           {
                //vector<string> selectedCols  = QueryService::split(queryWordList[i+1],',');
                select = queryWordList[i+1];
               
                
           }else if (queryWordList[i]=="from")
           {
                from = queryWordList[i+1];
   

           }else if(queryWordList[i]=="relate")
           {

                char _delimiter = '=';
                
                vector<string> paraList = QueryService::split(queryWordList[i+1],_delimiter);

                QueryService::replaceUnderscoresWithSpaces(paraList[1]);
                col1 = paraList[0];
                data1 = paraList[1];

              
               
                
                vector<string> paraList2 = QueryService::split(queryWordList[i +2],_delimiter);

                QueryService::replaceUnderscoresWithSpaces(paraList2[1]);
                col2 = paraList2[0];
                data2 = paraList2[1];

   
           }
            i = i+2;
        
        }

    }

};