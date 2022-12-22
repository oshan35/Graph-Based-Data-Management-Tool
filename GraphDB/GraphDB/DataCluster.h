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
	vector<Tree> coulmnTrees;
	Graph graph;

	vector<vector<Node*>> createNodes(vector < vector<variant<int, double, string>>> rows, vector<string> firstrow) {// should first row be given seperately
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



	void createTrees(vector<vector<Node*>> nodeRawData){
		for (int col = 0; col < nodeRawData.at(0).size(); col++)
		{

			vector<Node*> nodeCol;
			for (int row = 0; row < nodeRawData.size(); row++)
			{
				nodeCol.push_back(nodeRawData[col][row]);
			}

			Tree newTree;
			newTree.createTree(nodeCol);

			coulmnTrees.push_back(newTree);
		}
		
	}

	void createGraph(vector<vector<Node*>> nodeRawData){
		Node* indexNode;
		for(int row=0; row < nodeRawData.size(); row++){
			Node* prev = nullptr;
			for(int col=0; col < nodeRawData[0].size(); col++){
				Node* curr = nodeRawData[row][col];
				if(col == 0){
					indexNode->addOutRelation(row,curr);
					prev = curr;
				}else{
					graph.insertNode(prev,curr,row);
					prev = curr;
				}
			}
		}
	}

	public:
	void createDataCluster(vector < vector<variant<int, double, string>>> rows, vector<string> firstrow){
		vector<vector<Node*>> rowNodeData = createNodes(rows, firstrow);
		createTrees(rowNodeData);
		createGraph(rowNodeData);
	}




};

