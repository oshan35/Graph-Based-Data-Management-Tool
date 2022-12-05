#pragma once
#include<iostream>
#include<map>


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

	int hashValue()
	{
		int h = hash;
		if (h == 0 && count > 0)
		{
			int off = offset;
			char val[] = value;
			int len = count;

			for (int i = 0; i < len; i++)
			{
				h = 31 * h + val[off++];
			}
			hash = h;
		}
		return h;
	}
	

};

