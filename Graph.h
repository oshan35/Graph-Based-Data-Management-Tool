#pragma once
#include<iostream>
#include "Node.h"
#include <queue>
#include <unordered_set>
using namespace std;

class Graph
{
	int numOfNodes;
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

	
	vector<vector<Node*>> findRelationship(Node* start,Node* end){
		
		
		vector<vector<Node*>> res;
		vector<Node*>input;
		vector<vector<Node*>> res_got = findInPath(start, end, res, input, 0);
		if (res_got.empty()) {
			res_got= findOutPath(start, end, res, input, 0);
		}
		return res_got;
	}


	
	vector<vector<variant<int, double, string>>> searchByIndexes(vector<int> indexVector,vector<variant<int, double, string>> columns ){
		vector<vector<variant<int, double, string>>> searchResults;
		for(int i=0;i<indexVector.size();i++){
			vector<variant<int, double, string>> resultRow;

			int index = indexVector[i];

			Node* currentNode = indexNode->getOutRelation(index);

			while (currentNode!=nullptr)
			{
				if (std::find(columns.begin(), columns.end(), currentNode->getLabel()) != columns.end())
				{
					resultRow.push_back(currentNode->getData());
				}
				
				currentNode = currentNode->getOutRelation(index);
			}
			

			searchResults.push_back(resultRow);
			
		}

		return searchResults;

	}

	vector<int> NodeToIndex(Node* node){
		map<int,Node*> inRelations = node->getInMap();
		vector<int> rowNumbers;
		for(auto& connection:inRelations){
			rowNumbers.push_back(connection.first);
		}

		return rowNumbers;

	}


	vector<vector<int>> bfs(Node* start, Node* target) {
		queue<Node*> q;
		unordered_set<Node*> visited;
		unordered_map<Node*, Node*> parent;
		vector<vector<int>> path;

		q.push(start);
		visited.insert(start);

		while (!q.empty()) {
			Node* current = q.front();
			q.pop();

			if (current == target) {
				while (current != start) {
					path.insert(path.begin(), NodeToIndex(current));
					current = parent[current];
				}
				path.insert(path.begin(), NodeToIndex(start));
				return path;
			}

			for (auto& neighbor : current->getNeighbors()) {
				if (visited.find(neighbor.second) == visited.end()) {
					q.push(neighbor.second);
					visited.insert(neighbor.second);
					parent[neighbor.second] = current;
				}
			}
		}

		return path;
	}


	

};

