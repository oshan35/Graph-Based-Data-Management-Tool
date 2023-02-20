
#include <iostream>
#include <string>
#include "DataCluster.h"
#include <sstream>
#include "Graph.h"
#include <iostream>
#include <sstream>
#include "FileManager.h"
#include "DataClusterManager.h"
#include "QueryEngine/QueryDecoder.h"
#include "Service.h"
#include "stdexcept"
#include <variant>
//#include "QueryEngine/Query.h"
#include "QueryEngine/RelationQuery.h"



using namespace std;

bool containsSubstring(const std::string& mainString, const std::string& substring) {
    return mainString.find(substring) != std::string::npos;
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

int main(){
    DataClusterManager* dataclusterManager = new DataClusterManager();
    string input;

    cout<<"runcommand> ";

    while (getline(std::cin, input))
    {
        
        if(containsSubstring(input,"create-cluster")){
            vector<string> commandInput = split(input,' ');
            string clusterName = commandInput[1];
            string filepath = commandInput[2];

            try
            {
                vector<vector<string>> rawData = readCSVFile(filepath);
                dataclusterManager->createDataCluster(clusterName,rawData);
                cout <<"-----"<<clusterName << " Data Cluster created---"<<endl;

            }
            catch(const std::exception& e)
            {
                std::cerr << e.what() << '\n';
                std::cout<<"Error creating cluster..Check Your File path again!"<<endl;
            }
            
        }else if (containsSubstring(input,"run-query"))
        {
            QueryDecoder decoder;
            string query;
            string line;
            cout<<">";
            while (getline(std::cin,line))
            {
                // Query *queryObj=decoder.createQuery(query);
                if(line.back()==';'){
                    line.erase(line.length()-1);
                    query+=line;
                    break;
                }else{
                    line=line+" ";
                    query+=line;
                }
                cout<<">";
            }

            Query *queryObj = decoder.createQuery(query);
             
          
            cout<<queryObj->select<<endl;
            if(queryObj->queryId == "012") {
                WhereQuery* wQueryObj = static_cast<WhereQuery*>(queryObj);

                variant<int, double, string>  convertTargetCol=dataclusterManager->convertRawData(wQueryObj->colName);
                variant<int, double, string>  convertTargetData=dataclusterManager->convertRawData(wQueryObj->data);
              
                dataclusterManager->getAllConnections(queryObj->from,queryObj->select,convertTargetCol,convertTargetData);
            }else if(queryObj->queryId == "013") {

                RelationQuery* rQueryObj = static_cast<RelationQuery*>(queryObj);
                
                rQueryObj->toString();
                dataclusterManager->getRelations(queryObj->from,rQueryObj->col1,rQueryObj->data1,rQueryObj->col2,rQueryObj->data2);
            }       
            
        }else if(input == "exit"){
            break;
        }

        cout<<"runcommand> ";
        
    }
    


}