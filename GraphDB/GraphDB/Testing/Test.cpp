#include<iostream>
#include<variant>
using namespace std;

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
            //isInt = false;
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

int main(){
    string doubleTest = "92.3.4";
    string intTest = "23";
    string stringTest = "2b.12";

    variant<int, double, string> result = convertRawData(stringTest);

}
