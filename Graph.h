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



	void remove_spaces(std::variant<int, double, std::string>& data) {
		if (std::holds_alternative<std::string>(data)) {
			std::string str_data = std::get<std::string>(data);
			str_data.erase(0, str_data.find_first_not_of(" "));
			str_data.erase(str_data.find_last_not_of(" ") + 1);
			data = std::move(str_data);
		}
	}
	
	vector<vector<variant<int, double, string>>> searchByIndexes(vector<int> indexVector,vector<variant<int, double, string>> columns ){
		vector<vector<variant<int, double, string>>> searchResults;
		for(int i=0;i<indexVector.size();i++){
			vector<variant<int, double, string>> resultRow;

			int index = indexVector[i];

			Node* currentNode = indexNode->getOutRelation(index);

			while (currentNode!=nullptr)
			{
				variant<int,double,string> clusterCol =currentNode->getLabel();
				remove_spaces(clusterCol);
				//std::visit([](const auto& value) { std::cout <<"Test1: "<< value<<" "; }, columns[0]);
				//std::visit([](const auto& value) { std::cout <<"Test2: "<< value<<" "; }, currentNode->getLabel());
				if (std::find(columns.begin(), columns.end(), clusterCol) != columns.end())
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

	void insertUnique(vector<int> &target, vector<int> &source){
		for(int index:source){
			if (!(find(target.begin(),target.end(),index) != target.end()))
			{
				target.insert(target.begin(),index);
			}
			
		}

	}


	vector<int> bfs(Node* start, Node* target) {
		queue<Node*> q;
		unordered_set<Node*> visited;
		unordered_map<Node*, Node*> parent;
		//vector<vector<int>> path;
		vector<int> path;

		q.push(start);
		visited.insert(start);

		while (!q.empty()) {
			Node* current = q.front();
			q.pop();
			//std::visit([](const auto& value) { std::cout <<"curr Node data "<< value; }, current->getData());

			if (current == target) {
			    //std::visit([](const auto& value) { std::cout <<"curr Node data"<< value; }, current->getData());
				//std::visit([](const auto& value) { std::cout <<"target Node data"<< value; }, target->getData());
				
				while (current != start) {
					vector<int> connections = NodeToIndex(current);
					insertUnique(path,connections);
					//path.insert(path.begin(), NodeToIndex(current));
					current = parent[current];
				}
				vector<int> connections = NodeToIndex(current);
				insertUnique(path,connections);
				//path.insert(path.begin(), NodeToIndex(start));
				return path;
			}

			for (Node* neighbor : current->getNeighbors()) {
				//std::visit([](const auto& value) { std::cout <<"Node data "<< value<<endl; }, neighbor->getData());
				if (visited.find(neighbor) == visited.end()) {
					
					q.push(neighbor);
					visited.insert(neighbor);
					parent[neighbor] = current;
				}
			}
		}

		return path;
	}


	

};

