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

	Graph(){
		Node* newNode = new Node();
		indexNode = newNode;
	}

	Graph(Node* indexNode) {
		this->indexNode = indexNode;
		numOfNodes = 1;
	}

	void insertNode(Node* prevNode, Node* node, int index) {
		node->addInRelation(index, prevNode);

		prevNode->addOutRelation(index, node);

		numOfNodes++;
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

