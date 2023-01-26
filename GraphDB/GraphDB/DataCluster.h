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
#include <queue>
#include <unordered_map>
using namespace std;
class DataCluster
{public:
	vector<Tree*> coulmnTrees;
	Graph* graph;

	vector<vector<Node*>> createNodes(vector < vector<variant<int, double, string>>> rowsInVector) {
		std::vector<std::vector<Node*>> rowsOutVector(rowsInVector.size(), std::vector<Node*>(rowsInVector[0].size()));

		
		for (int column = 0; column < rowsInVector[0].size(); column++) {
			map<variant<int, double, string>, Node*> nodeMap;
			vector<Node*> vecEle;

			for (int row = 1; row < rowsInVector.size(); row++) {
				Node* node = new Node(rowsInVector[0][column], rowsInVector[row][column]);
				nodeMap[rowsInVector[row][column]] = node;
			}

			for (int row = 1; row < rowsOutVector.size(); row++) {
				rowsOutVector[row].push_back( nodeMap[rowsInVector[row][column]]);
			}

		}
		return rowsOutVector;
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

