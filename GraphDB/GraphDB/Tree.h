#pragma once
#include<stdio.h>
#include<iostream>
#include "Node.h"
#include <vector>
#include<algorithm>

using namespace std;
class Tree
{   Node* root;

public:
	Tree(string label,string data) {// do we have to make special kind of node to store labels of root node of a tre eor can we implement a new constructor to node class
		Node* temp = new Node(label,data);
		root = temp;
	}
	Tree() {
		root = NULL;
	}
	void setRoot(Node* root1) {
		root = root1;
	}
	Node* createTree(vector <Node*> Data) {
		
		return (vectorToBST(Data, 0, Data.size() - 1));
		//returns the root of the created tree

	}
	Node* vectorToBST(vector <Node*> Data, int start, int end) {
		if (start > end) {
			return NULL;
		}
		int middle = (start + end) / 2;

		Data[middle]->setLeft(vectorToBST(Data, start, middle - 1))  ;
		Data[middle]->setRight(vectorToBST(Data, middle + 1, end));
		return Data[middle];
	}
	Node* searchTree(Node* root, string target) {
		if (target > root->getData()) {
			root = searchTree(root->getright(), target);
			return root;

		}
		else if (target < root->getData()) {
			root = searchTree(root->getLeft(), target);
			return root;
		}
		else
			return root;
	}


};

