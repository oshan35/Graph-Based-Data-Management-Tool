#pragma once
#include<iostream>
#include "Node.h"
using namespace std;

class Graph
{
	Node* indexNode;

public:
	Graph(Node* indexNode) {
		this->indexNode = indexNode;
	}

	void insertNode(Node* prevNode, Node* node, int index) {
		node->addInRelation(index, prevNode);
		prevNode->addOutRelation(index, node);
	}

	Node* searchNode(string data) {


	}



};

