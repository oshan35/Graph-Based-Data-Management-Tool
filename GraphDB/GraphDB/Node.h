#pragma once
#include<iostream>
#include<map>
#include<boost/functional/hash.hpp>

using namespace std;

class Node
{
	string label;
	string data;
	map<int, Node*> inMap;
	map<int, Node*> outMap;

public:
	Node(string label, string data) {
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


	int hashCode()
	{
		boost::hash<std::string> string_hash;

		return string_hash("Hash me");
	}
	

};

