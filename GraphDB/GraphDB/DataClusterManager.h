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
        
    }
}