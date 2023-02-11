#include<iostream>
#include<vector>
#include<fstream>
#include<sstream>
#include<map>
#include <cstring>
#include<stdio.h>
using namespace std;

fstream openFile(string path){

    fstream file;
    file.open(path, ios::out | ios::app);

    return file;
    
}


vector<vector<string>> readCSVFile(string path){
    map<int, vector<string>> rawDataMap;
    
    vector<vector<string>> content;
    vector<string> row;
    string line, word;
 
    fstream file (path, ios::in);
    if(file.is_open())
    {
        char bom[3];
        file.read(bom, 3);
        if (bom[0] != '\xEF' || bom[1] != '\xBB' || bom[2] != '\xBF') {
            // BOM not present, move the file pointer back to the beginning
            file.seekg(0, std::ios::beg);
        }

        while(getline(file, line))
        {
            row.clear();
            
            stringstream str(line);
            
            while(getline(str, word, ','))
            row.push_back(word);
            content.push_back(row);
        }
    }
    else{
        cout<<"Could not open the file\n";
        
        for(int i=0;i<content.size();i++)
        {
        for(int j=0;j<content[i].size();j++)
        {
            cout<<content[i][j]<<" ";
        }
        cout<<"\n";
        }
    }

    
    return content;

}


