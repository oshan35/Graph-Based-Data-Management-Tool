#include<iostream>
#include<map>
#include<vector>
#include<variant>
#include"DataCluster.h"
using namespace std;

class DataClusterManager{
    vector<DataCluster> dataClusters;

    public:
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


    void createDataCluster(vector<vector<*string>> *rawData){
        vector<vector<variant<int, double, string>> *convertedRawData;

        for(int row=0;row<rawData->size();row++){
            vector<varient<int, double, string>> *dataRow;
            for (int col=0;col<rawData[0].size();col++)
            {
                variant<int, double, string> convertedData = convertedData(rawData[row][col]);
                dataRow.push_back(convertedData);
            }
            convertRawData.push_back(dataRow);

            
        }

        DataCluster* newDataCluster= new DataCluster(convertRawData);
        dataClusters.push_back(newDataCluster);
    }
}