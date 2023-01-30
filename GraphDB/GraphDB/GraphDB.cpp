
#include <iostream>
#include <string>
#include "DataCluster.h"
#include <sstream>
#include "Graph.h"
#include <iostream>
#include <sstream>
#include "FileManager.h"
#include "DataClusterManager.h"
using namespace std;
struct make_string_functor {
	std::string operator()(const std::string& x) const { return x; }
	std::string operator()(int x) const { return std::to_string(x); }
};
variant<int, double, string>  convertData(string rawData) {
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
		}
		else if (!isdigit(rawData[index]))
		{
			isInt = false;
		}


	}

	if (isDouble && isInt) {
		doubleValue = stod(rawData);
		convertedData = doubleValue;
	}
	else if (isInt) {
		intValue = stoi(rawData);
		convertedData = intValue;
	}
	else {
		stringValue = rawData;
		convertedData = stringValue;
	}

	return convertedData;

}
int main() {
	DataClusterManager* dataclusterManager = new DataClusterManager();
	cout << "Welcome to peoject Nebula" << endl;
	while (true) {
		cout << "1. Add Data Cluster" << std::endl;  //should there be an option to view data cluster
		cout << "2. Select Data Cluster" << std::endl;
		cout << "3. Exit" << std::endl;
		cout << "Enter your choice" << endl;
		int choice;
		cin >> choice;
		switch (choice) {
		case(1): {
			cout << "Enter a name for the Data Cluster" << endl;
			string clusterName;
			cin >> clusterName;
			
			std::cout << "Enter the file path: ";
			string path;
			cin >> path;

			
			
			vector<vector<string>> rawData = readCSVFile(path);
			
			dataclusterManager->createDataCluster(clusterName, rawData);
			cout <<"-----"<<clusterName << "Data Cluster created---"<<endl;

			}
			  
		case(2): {
			cout << "Select a cluster " << endl;
			for (const auto& [key, value] : dataclusterManager->getDataClusters()) {
				std::cout <<  value << std::endl;
			}
			cout << "Enter your choice" << endl;
			string clustername;
			cin >> clustername;
			while (true) {
				cout << "1. Find Path between two data" << endl;
				cout << "2. Find Relationship between a data and a column" << endl;
				cout << "3. search if" << endl;
				int Clusterchoice;
				cin >> Clusterchoice;
				switch (Clusterchoice) {
				case(1): {
					cout << "Enter column 1" << endl;
					string col1;
					cin >> col1;
					cout << "Enter column 2" << endl; 
					string col2;
					cin >> col2;
					cout << "Enter data 1" << endl;
					string data1;
					cin >> data1;
					variant<int, double, string>  converteddata1=convertData(data1);
					cout << "Enter data 2" << endl;
					string data2;
					cin >> data2;
					variant<int, double, string>  converteddata2 = convertData(data2);
					vector< vector<variant<int, double, string>>> Paths=dataclusterManager->getDataClusters()[clustername]->FindPaths(converteddata1, converteddata2, col1, col2);
					cout << " ------------------------------------------------------------- ";
					for (int i = 0; i < Paths.size(); i++) {
						for (int j = 0; j < Paths[i].size(); j++) {
							std::visit([](const auto& value) { std::cout << value; }, Paths[i][j]);
							if(j!= Paths[i].size()-1)
								cout << "-->";
						}
						cout << endl;
					}
					cout << " ------------------------------------------------------------- ";
				}
				case(2): {
					
				}
				case(3): {
					cout << "Enter Column Name" << endl;
					string colName;
					cin >> colName;
					cout << "select the condition" << endl;
					cout<<"1. >"<<endl;
					cout<<"2. <"<<endl;
					cout<<"3. >=" << endl;
					cout<<"4. <=" << endl;
					int selection;
					cin>>selection;
					cout<<" Enter data nedd to be checked";
					string datac;
					cin >>datac;
					variant<int, double, string> dataconverted = convertData(datac);
					vector<variant<int, double, string>> res;
					switch(selection){
					case(1):{
						 res= dataclusterManager->getDataClusters()[clustername]->searchIF(colName,dataconverted,1);
						}
					case(2):{
						res = dataclusterManager->getDataClusters()[clustername]->searchIF(colName, dataconverted, 2);
						}
					case(3): {
						res = dataclusterManager->getDataClusters()[clustername]->searchIF(colName, dataconverted, 3);
					}
					case(4): {
						res = dataclusterManager->getDataClusters()[clustername]->searchIF(colName, dataconverted, 4);
					}
					}
					cout << " ------------------------------------------------------------- ";
					
					for(int i=0;i<res.size();i++){
						std::visit([](const auto& value) { std::cout << value; }, res[i]);
					}
					cout << " ------------------------------------------------------------- ";


				}
				}

			}
		}
		case(3): {

		}
		}
	
	}




}
