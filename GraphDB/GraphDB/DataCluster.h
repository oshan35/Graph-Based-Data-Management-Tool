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
#include <sstream>
using namespace std;
class DataCluster
{
	vector<Tree*> coulmnTrees;
	Graph* graph;

	vector<vector<Node*>> createNodes(vector < vector<variant<int, double, string>>> rows) {// should first row be given seperately
		vector<vector<Node*> > arr(rows.size(), vector<Node*>(rows[0].size()));
		for (int i = 0; i < rows[0].size(); i++) {
			map<variant<int, double, string>, vector<pair<int, int>>> nodeMap;

			for (int j = 1; j < rows.size(); j++) {

				if (nodeMap.count(rows[j][i]) == 0) {
					vector<pair<int, int>> v1 = { { j,i } };
					nodeMap.insert(std::make_pair(rows[j][i], v1));
				}
				else nodeMap[rows[j][i]].push_back({ j,i });
			}

			for (const auto& [k, v] : nodeMap) {
				Node* newNode = new Node(stringify(rows[0][i]), k);
				for (int index = 0; index < v.size(); index++) {

					arr[v[index].first][v[index].second] = newNode;
				}

			}

		}
		return arr;
	}
	string stringify(variant<int, double, string> const& value) {
		if (int const* pval = std::get_if<int>(&value))
			return std::to_string(*pval);

		if (double const* pval = std::get_if<double>(&value))
			return to_string(*pval);

		return get<string>(value);
	}

	vector<Tree*> createTrees(vector<vector<Node*>> nodeRawData){
		vector<Tree*> columnList;
		for (int col = 0; col < nodeRawData.at(0).size(); col++)
		{


			vector<Node*> nodeCol;
			for (int row = 0; row < nodeRawData.size(); row++)
			{
				auto it = find(nodeCol.begin(), nodeCol.end(),nodeRawData[row][col]);
				
				if (it != nodeCol.end()){
					continue;
				}else{
					nodeCol.push_back(nodeRawData[row][col]);
				}

			}

			Tree* newTree=new Tree();
			newTree->createTree(nodeCol);

			columnList.push_back(newTree);
		}

		return columnList;
		
	}

	Graph* createGraph(vector<vector<Node*>> nodeRawData){
		
		Graph* newGraph = new Graph();

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
	DataCluster(vector < vector<variant<int, double, string>>> stringNodesVector){

		vector<vector<Node*>> createdNodeVector = createNodes(stringNodesVector);

		graph = createGraph(createdNodeVector);
		coulmnTrees = createTrees(createdNodeVector);
	}

};

