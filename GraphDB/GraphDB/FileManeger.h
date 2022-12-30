#pragma once
#include<iostream>
#include<fstream>
#include <string>
#include <sstream> 
#include <vector>


using namespace std;

class FileManeger
{private:
	string FileName;

 public:
	ifstream OpenFile(string filePath) {
		ifstream filepath;
		if (filepath.fail()) {
			cout << "Unable to open file"<<filePath;
		}
		else
			filepath.open(filePath);
		return filepath;
	}
	
	string WriteFile(string filePath) {
    // Read the Data from the file
    // as String Vector
        vector<string> row;
        string line, word, temp;

        while (filePath > temp) {

            row.clear();

            // read an entire row and
            // store it in a string variable 'line'
            getline(filePath, line);

            // used for breaking words
            stringstream s(line);

            // read every column data of a row and
            // store it in a string variable, 'word'
            while (getline(s, word, ', ')) {

                // add all the column data
                // of a row to a vector
                row.push_back(word);
            }

          
        }
       
    }
};

