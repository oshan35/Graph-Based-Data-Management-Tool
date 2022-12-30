#pragma once
#include<iostream>
#include<map>
#include<variant>

using namespace std;

class Node
{
	string label;
	variant<int, double, string> data;
	map<int, Node*> inMap;
	map<int, Node*> outMap;
	Node* left;
	Node* right;


public:
	Node(){
	}
	

	Node(string label, variant<int, double, string> data) {
		this->label = label;
		this->data = data;
	}

	void updateData(variant<int, double, string> newData) {
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

	Node* getright() {
		return right;
	}
	variant<int, double, string> getData() {
		return data;
	}

	bool operator==(const Node& other) const {
    	return data == other.data && label == other.label;
  	}

};

