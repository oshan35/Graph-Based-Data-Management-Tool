#pragma once
#include<iostream>
#include<map>


using namespace std;

class Node
{
	string label;
	auto data;
	map<int, Node*> inMap;
	map<int, Node*> outMap;
	Node* left;
	Node* right;


public:
	Node(string label, auto data) {
		this->label = label;
		this->data = data;
	}

	void updateData(string newData) {
		this->data = newData;
	}

	void addOutRelation(int index,Node* relation) {
		outMap[index] = relation;
	}

	void addInRelation(int index, Node* relation) {
		inMap[index] = relation;
	}

	void setLeft(Node* left) {
		this->left = left;
	}

	void setRight(Node* right) {
		this->right = right;
	}

	Node* getLeft() {
		return left;
	}

	Node* right() {
		return right;
	}

};

