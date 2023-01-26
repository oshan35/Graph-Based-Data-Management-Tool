#pragma once
#include<stdio.h>
#include<iostream>
#include "Node.h"
#include <vector>
#include<algorithm>
#include<variant>
#include <map>
#include "Tree.h"
#include "Graph.h"
using namespace std;
class DataCluster
{
	map<string,Tree*>  coulmnTrees;
	Graph* graph;
	
	vector<vector<Node*>> createNodes(vector<vector<variant<int, double, string>>> rows) {// should first row be given seperately
		vector<vector<Node*> > arr(rows.size(), vector<Node*>(rows[0].size()));
		for (int i = 0; i < rows[0].size(); i++) {
			map<variant<int, double, string>, vector<pair<int, int>>> nodeMap;

			for (int j = 0; j < rows.size(); j++) {

				if (nodeMap.count(rows[j][i]) == 0) {
					vector<pair<int, int>> v1 = { { j,i } };
					nodeMap.insert(std::make_pair(rows[j][i], v1));
				}
				else nodeMap[rows[j][i]].push_back({ j,i });
			}
			vector<vector<Node*> > arr(rows.size(), vector<Node*>(rows[0].size()));

			for (const auto& [k, v] : nodeMap) {
				for (int index = 0; index < v.size(); index++) {
					Node* newNode = new Node(firstrow[i], k);
					arr[v[index].first][v[index].second] = newNode;
				}
				return arr;
			}
		}
	}



	

	map<string,Tree*>  createTrees(vector<vector<Node*>> nodeRawData){
		map<string,Tree*> columnList;
		for (int col = 0; col < nodeRawData.at(0).size(); col++)
		{
			string colName = NULL;
			vector<Node*> nodeCol;
			for (int row = 0; row < nodeRawData.size(); row++)
			{
				if(row==0){
					colName = nodeRawData[row][col]
					continue;
				}
				auto it = find(nodeCol.begin(), nodeCol.end(),nodeRawData[row][col]);
				
				if (it != nodeCol.end()){
					continue;
				}else{
					nodeCol.push_back(nodeRawData[row][col]);
				}

			}

			Tree* newTree=new Tree();
			newTree->createTree(nodeCol);

			columnList[colName] = newTree;
		}

		return columnList;
		
	}

	Graph* createGraph(vector<vector<Node*>> nodeRawData){
		Node* indexNode = new Node();
		Graph* newGraph = new Graph(indexNode);

		for(int row=0; row < nodeRawData.size(); row++){
			Node* prev = nullptr;
			for(int col=0; col < nodeRawData[0].size(); col++){
				Node* curr = nodeRawData[row][col];
				if(col == 0){
					graph->indexNode->addOutRelation(row,curr);
					prev = curr;
				}else{
					graph->insertNode(prev,curr,row);
					prev = curr;
				}
			}
		}

		return newGraph;
	}


	public:
	DataCluster(){
		Node* indexNode = new Node();
		graph = new Graph(indexNode);
	}

	
	void searchTreeNode(string colName, variant<int, double, string> dataPoint){
		Tree* currentTree;
		try
		{
			currentTree = coulmnTrees[colName];

		}
		catch(const std::exception& e)
		{
			std::cerr << "Column Name not found"<< '\n';
		}
		
		
		Node* dataPoint = currentTree->searchTree(currentTree->getRoot(),dataPoint);

		vector<int> keyList;

		for ( auto it = dataPoint->getInMap().begin(); it != dataPoint->getInMap().end(); ++it  )
		{
			keyList.push_back(it->first);
		} 


		
	}


	
	void createDataCluster(vector < vector<variant<int, double, string>>> rows){
		vector<vector<Node*>> rowNodeData = createNodes(rows);
		graph = createGraph(rowNodeData);
		coulmnTrees = createTrees(rowNodeData);
	}


};

