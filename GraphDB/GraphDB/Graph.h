#pragma once
#include<iostream>
#include "Node.h"
#include <queue>
#include <unordered_set>
using namespace std;

class Graph
{


	int numOfNodes;

public:
	Node* indexNode;

	Graph(){}

	Graph(Node* indexNode) {
		this->indexNode = indexNode;
		numOfNodes = 1;
	}

	void insertNode(Node* prevNode, Node* node, int index) {
		node->addInRelation(index, prevNode);

		prevNode->addOutRelation(index, node);

		numOfNodes++;
	}

	vector<variant<int, double, string>> searchByIndexes(vector<int> indexVector,vector<string> columns ){
		vector<vector<variant<int, double, string>>> searchResults;
		for(int i=0;i<indexVector.size();i++){
			vector<variant<int, double, string> resultRow;

			int index = indexVector[i];

			Node* currentNode = indexNode->getOutRelation(index);

			while (!currentNode->getOutMap.isEmpty())
			{
				if (std::find(columns.begin(), columns.end(), currentNode->getLabel) != columns.end())
				{
					resultRow.push_back(currentNode->getData);
				}
				
				currentNode = currentNode->getOutRelation(index);
			}
			
		}

		return searchResults;

	}

	void searchNode() {
		Node* start = indexNode;
		queue<Node*> q;

		unordered_set<Node*> visited;

		q.push(start);

		visited.insert(start);

		while (!q.empty()) {
			Node* curr = q.front();
			q.pop();
			map<int, Node*> outmap;

			for (auto i = outmap.begin(); i != outmap.end(); i++) {
				if (!visited.count(i->second)) {
					q.push(i->second);
					visited.insert(i->second);
				}
			}
				
		}



		
	}



};

