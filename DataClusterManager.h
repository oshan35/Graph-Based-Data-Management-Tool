#include<iostream>
#include<map>
#include<vector>
#include<variant>
#include"DataCluster.h"
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
                variant<int, double, string> convertedData = convertRawData(rawData[row][col]);
                dataRow.push_back(convertedData);
            }
            convertedRawData.push_back(dataRow);           
        }

        DataCluster* newDataCluster= new DataCluster(convertedRawData);
        dataClusters[clusterName]=(newDataCluster);
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
};