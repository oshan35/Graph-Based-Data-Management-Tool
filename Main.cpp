
#include <iostream>
#include <string>
#include "DataCluster.h"
#include <sstream>
#include "Graph.h"
#include <iostream>
#include <sstream>
using namespace std;
struct make_string_functor {
	std::string operator()(const std::string& x) const { return x; }
	std::string operator()(int x) const { return std::to_string(x); }
};
int main() {
	
	vector<vector<variant<int, double, string>>> RowData
	{
		{"Name", "Age", "District", "University", "Faculty"},
		{"Ashen", 22, "Gampha", "Ruhuna", "Engineering"},
		{"Nehara", 23, "Matara", "Ruhuna", "Engineering"},
		{"Oshan", 22, "Colombo", "Moratuwa", "Manegement"},
		{"Dahami", 21, "Galle", "Japura", "Medicine"},
		{"Sam", 22, "Vauniya", "Jaffna", "Engineering"}


	};
	DataCluster* cluster = new DataCluster(RowData);
	//vector<vector<Node*>>result = cluster->FindPaths(22, "Engineering", "Age", "Faculty");
	//vector<variant<int, double, string>> res = cluster->searchIF("Age", "> 21");
	//findRelationship Cluster
    cout<<"cluster size: "<<cluster->coulmnTrees.size()<<endl;

    variant<int,double,string> datapoint = cluster->coulmnTrees["Name"]->getRoot()->getData();
    cout<<"Name col data: "<<std::visit(make_string_functor(), datapoint)<<endl;

	variant<int, double, string> data = "Ruhuna";
	vector<variant<int, double, string>> targetCols{"Name","District"};

	

	vector<vector<variant<int, double, string>>> allConnections = cluster->getConnections(3,targetCols,data);


	cout<<"----------------------------------------------"<<endl;

	cout<<"col Name: "<<std::visit(make_string_functor(), cluster->coulmnTrees[3]->getRoot()->getLabel())<<endl;

	cout<<"is empty: "<<allConnections.empty()<<endl;

	for ( int i=0;i<allConnections.size();i++)
	{
		for (int j=0;j<allConnections[i].size();j++)
		{
			variant<int,double,string> point = allConnections[i][j];

			cout<<std::visit(make_string_functor(), point)<<" ";
		}
		cout<<endl;
		
	}

	cout<<"----------------------------------------------"<<endl;
	






	//findRelationship
	/*
	Graph* res_created = cluster->graph;
	vector<Tree*> tree = cluster->coulmnTrees;
	Node* start=tree[1]->searchTree(tree[1]->getRoot(), 22);
	Node* end = tree[4]->searchTree(tree[4]->getRoot(), "Engineering");
	vector<vector<Node*>>result = res_created->findRelationship(start, end);*/
	
	
	// for (int i = 0; i < result.size(); i++) {
	// 	for (int j = 0; j < result[i].size(); j++) {


	// 		std::cout << std::visit(make_string_functor(), result[i][j]->getData()) << "\n";
	// 	}
	// 	cout << endl;
	// }
	// for (int j = 0; j < res.size(); j++) {


	// 	std::cout << std::visit(make_string_functor(), res[j]) << "\n";
	// }
	//
	
	/*
	* vector<variant<int, double, string>> res1;
	vector<variant<int, double, string>> res = tree[2]->searchIfLarger(tree[1]->getRoot(), 21, res1);
	
	cout << endl;
	*/
	//searchIf
	
	//
	return 0;
}