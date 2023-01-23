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

vector<vector<Node*>> findPath(Node* start, Node* end, vector<vector<Node*>>Paths, vector<Node*>newPath, int level) {
		level++;
		if (start == end) {
			Paths.push_back(newPath);
			return Paths;
		}
        if (start==NULL)
            return {{}};
		for (const auto& [key, value] : start->getInMap()) {
			if (level == 1)
				newPath = { start,value};
			else {
				for (int i = 0;i<newPath.size();i++) {
					if ( newPath[i]->getLabel() == value->getLabel())
						newPath.erase(newPath.begin() + i);
				}

				newPath.push_back(value);
			}
				
				
			Paths = findPath(value, end, Paths, newPath, level);
		}
		return Paths;
	}



};

