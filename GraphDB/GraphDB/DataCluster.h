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
{
public:
	vector<Tree*> coulmnTrees;
	Graph* graph;

	vector < vector<Node*>> createNodes(vector < vector<variant<int, double, string>>> rows) {
		vector<vector<Node*> > arr(rows.size()-1, vector<Node*>(rows[0].size()));
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
				Node* newNode = new Node(k, rows[0][i]);
				for (int index = 0; index < v.size(); index++) {

					arr[(v[index].first) - 1][(v[index].second)] = newNode;
				}

			}


		}
		return arr;

	}


	void createTrees(vector<vector<Node*>> nodeRawData) {
		
		
		for (int col = 0; col < nodeRawData.at(0).size(); col++)
		{
			vector<Node*> nodeCol;
			for (int row = 0; row < nodeRawData.size(); row++)
			{
				auto it = find(nodeCol.begin(), nodeCol.end(), nodeRawData[row][col]);

				if (it != nodeCol.end()) {
					continue;
				}
				else {
					nodeCol.push_back(nodeRawData[row][col]);
				}

			}

			Tree* newTree = new Tree();
			newTree->createTree(nodeCol);

			coulmnTrees.push_back(newTree);
		}

		

	}

	Graph* createGraph(vector<vector<Node*>> nodeRawData) {
		Node* node = new Node(2, 5);
		Graph* newGraph = new Graph(node);

		for (int row = 0; row < nodeRawData.size(); row++) {
			Node* prev = nullptr;
			for (int col = 0; col < nodeRawData[0].size(); col++) {
				Node* curr = nodeRawData[row][col];
				if (col == 0) {
					newGraph->indexNode->addOutRelation(row, curr);
					prev = curr;
				}
				else {
					newGraph->insertNode(prev, curr, row);
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
		createTrees(createdNodeVector);
	}

};

