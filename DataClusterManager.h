#include<iostream>
#include<map>
#include<vector>
#include<variant>
#include"DataCluster.h"
#include "TextTable.h"
using namespace std;

class DataClusterManager{
    map<string,DataCluster*> dataClusters;



public:
    void createDataCluster(string clusterName,vector<vector<string>> rawData){
        vector<vector<variant<int, double, string>>> convertedRawData;

        for(int row=0;row<rawData.size();row++){
            vector<variant<int, double, string>> dataRow;
            for (int col=0;col<rawData[0].size();col++)
            {
                variant<int, double, string> convertedData = stringToVariant(rawData[row][col]);
                dataRow.push_back(convertedData);
            }
            convertedRawData.push_back(dataRow);           
        }

        DataCluster* newDataCluster= new DataCluster(convertedRawData);
        dataClusters[clusterName]=(newDataCluster);
    }

    std::variant<int, double, std::string> stringToVariant(const std::string& input) {
        try {
            return std::stoi(input);
        } catch (const std::invalid_argument&) {
            try {
                return std::stod(input);
            } catch (const std::invalid_argument&) {
                return input;
            }
        }
    }

    DataCluster* getDataClusters(string clustername) {
        return dataClusters[clustername];
    }

    vector<string> getClusterNames(){
        vector<string> namevec;
        for (auto const& [key, val] : dataClusters)
        {
            namevec.push_back(key);
        }
        
        return namevec;
    }

    variant<int, double, string>  convertRawData(string rawData){
        double doubleValue;
        int intValue;
        string stringValue;

        variant<int, double, string> convertedData;

        bool isInt = true;
        bool isDouble = false;

        for (int index = 0; index < rawData.length(); index++)
        {
            if (rawData[index] == '.' && !isDouble && isInt)
            {
                isDouble = true;
            }else if (!isdigit(rawData[index]))
            {
                isInt=false;
            }
            
            
        }

        if(isDouble && isInt){
            doubleValue = stod(rawData);
            convertedData = doubleValue;
        }else if(isInt){
            intValue = stoi(rawData);
            convertedData = intValue;
        }else{
            stringValue = rawData;
            convertedData = stringValue;
        }

        return convertedData;

    }

    vector<variant<int, double,string>> split(const std::string &str, char delimiter) {
        std::vector<variant<int, double,string>> tokens;
        std::stringstream ss(str);
        std::string token;
        while (std::getline(ss, token, delimiter)) {
            variant<int,double,string> convetred =convertRawData(token);
            tokens.push_back(convetred);
        }
        return tokens;
    }

    std::string variantToString(const std:: variant<int, double,string> &v) {
        switch (v.index()) {
            case 0:
                return std::to_string(std::get<int>(v));
            case 1:
                return std::to_string(std::get<double>(v));
            case 2:
                return std::get<std::string>(v);
        }
        return "";
    }

    void getAllConnections(string clusterName,string returnCols, variant<int, double,string> colName, variant<int,double,string> dataPoint){
       
    
    
        vector<variant<int, double,string>> returnColList;
        DataCluster* targetCluster = dataClusters[clusterName];

        //auto item = std::find(returnColList.begin(),returnColList.end(),"*");
        vector<vector<variant<int, double, string>>> connectionList;

        if(returnCols == "*"){
            returnColList = targetCluster->getColumnList();
            connectionList = targetCluster->getConnections(colName,returnColList,dataPoint);
        }else{
    
            returnColList = split(returnCols, ',');
            connectionList = targetCluster->getConnections(colName,returnColList ,dataPoint);
        }
        cout<<"Test: "<<connectionList[0].size()<<endl;


        TextTable t( '-', '|', '+' );

        for (int i = 0; i < returnColList.size(); i++)
        {
            string data = variantToString(returnColList[i]);
            // cout<<data<< " ";
            t.add(data);
        }
        t.endOfRow();
        

        for (int row = 0; row < connectionList.size(); row++)
        {
            
           for (int col = 0; col < connectionList[0].size(); col++)
           {
                string data = variantToString(connectionList[row][col]);
                t.add(data);
                
           }
           t.endOfRow();

           
        }


        t.setAlignment( 2, TextTable::Alignment::RIGHT );
        
        std::cout << t;
    }
};