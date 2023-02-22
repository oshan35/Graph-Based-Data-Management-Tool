
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
#include "stdexcept"
#include <variant>
#include <fstream>
#include <stdlib.h>

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

    vector<vector<string>> rawData = readCSVFile("./TestingData/TestData.csv");
    dataclusterManager->createDataCluster("student-cluster",rawData);

    vector<vector<string>> rawData2 = readCSVFile("./TestingData/Dummy-data.csv");
    dataclusterManager->createDataCluster("crime-Data-cluster",rawData2);

    vector<vector<string>> rawData3 = readCSVFile("./TestingData/TestData3.csv");
    dataclusterManager->createDataCluster("social-network-cluster",rawData3);
    cout<<"Welcome to Cluster-Math. This a console base application where you can manage \nyour unstructured tabula form data."<<endl;
    time_t now = time(0);
    char* dt = ctime(&now);
    std::cout<<"@" <<dt << std::endl;

    cout<<"Run help for more instructions."<<endl;
    cout<<" "<<endl;
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
            //for testing
            //query = "select Rate_ratio_NZ_average_rate from crime-Data-cluster where Territorial=Auckland";
            Query *queryObj;
            try
            {
                queryObj = decoder.createQuery(query);
            }
            catch(const std::exception& e)
            {
                std::cerr << e.what() << '\n';
                cout<<"Invalid Query!"<<endl;
                continue;
            }
            

            //Query *queryObj = decoder.createQuery(query);
             
            if(queryObj->queryId == "012") {
                WhereQuery* wQueryObj = static_cast<WhereQuery*>(queryObj);

                //wQueryObj->toString();

                variant<int, double, string>  convertTargetCol=dataclusterManager->convertRawData(wQueryObj->colName);
                variant<int, double, string>  convertTargetData=dataclusterManager->convertRawData(wQueryObj->data);

                try
                {
                    dataclusterManager->getAllConnections(queryObj->from,queryObj->select,convertTargetCol,convertTargetData);
                }
                catch(const std::exception& e)
                {
                    std::cerr << e.what() << '\n';
                }
                
              
                
            }else if(queryObj->queryId == "013") {
        
                RelationQuery* rQueryObj = static_cast<RelationQuery*>(queryObj);

                try
                {
                    dataclusterManager->getRelations(queryObj->from,rQueryObj->col1,rQueryObj->data1,rQueryObj->col2,rQueryObj->data2);
                }
                catch(const std::exception& e)
                {
                    std::cerr << e.what() << '\n';
                }
                

            }       
            
        }else if (input == "list-clusters")
        {
            dataclusterManager->listCluster();
        }else if(input == "help"){

            std::ifstream file("help.txt");
            if (file) {
                std::string line;
                while (std::getline(file, line)) {
                    std::cout << line << std::endl;
                }
            } else {
                std::cerr << "Error opening file " << "help" << std::endl;
            }

        }else if(input == "exit"){
            break;
        }else if(input == "clear"){
            system("cls");

        }else{
            cout<<"Invalid command run --help too read the instructions!"<<endl;
        }

        cout<<"runcommand> ";
        
    }

}
