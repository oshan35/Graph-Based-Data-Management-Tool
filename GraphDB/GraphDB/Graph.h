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


	vector<vector<Node*>> findInPath(Node* start, Node* end, vector<vector<Node*>>Paths, vector<Node*>newPath, int level) {
		level++;
		if (start == end) {
			Paths.push_back(newPath);
			return Paths;
		}
		if (start == NULL)
			return { {} };

		std::vector<Node*> values;
		for (auto& elem : start->getInMap()) {
			values.push_back(elem.second);
		}
		auto last = std::unique(values.begin(), values.end());
		values.erase(last, values.end());

		for (const auto value : values) {
			if (level == 1)
				newPath = { start,value };
			else {
				for (int i = 0; i < newPath.size(); i++) {
					if (newPath[i]->getLabel() == value->getLabel())
						newPath.erase(newPath.begin() + i);
				}

				newPath.push_back(value);
			}


			Paths = findInPath(value, end, Paths, newPath, level);
		}
		return Paths;

	}
	
	vector<vector<Node*>> findOutPath(Node* start, Node* end, vector<vector<Node*>>Paths, vector<Node*>newPath, int level) {
		level++;
		if (start == end) {
			Paths.push_back(newPath);
			return Paths;
		}
		if (start == NULL)
			return { {} };
		std::vector<Node*> values;
		for (auto& elem : start->getOutMap()) {
			values.push_back(elem.second);
		}
		auto last = std::unique(values.begin(), values.end());
		values.erase(last, values.end());

		for (const auto value: values) {
			if (level == 1)
				newPath = { start,value };
			else {
				for (int i = 0; i < newPath.size(); i++) {
					if (newPath[i]->getLabel() == value->getLabel())
						newPath.erase(newPath.begin() + i);
				}

				newPath.push_back(value);
			}


			Paths = findOutPath(value, end, Paths, newPath, level);
		}
		return Paths;

	}
/*
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
	}*/

};

