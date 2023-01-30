#pragma once
#include<stdio.h>
#include<iostream>
#include "Node.h"
#include <vector>
#include<algorithm>
#include<variant>
#include <map>
#include "Tree.h"
#include "Graph.h"
#include <sstream>
#include <queue>
#include <unordered_map>

using namespace std;
class DataCluster
{
public:
	vector<Tree*> coulmnTrees;
	Graph* graph;

	vector < vector<Node*>> createNodes(vector < vector<variant<int, double, string>>> rows) {
		vector<vector<Node*> > arr(rows.size()-1, vector<Node*>(rows[0].size()));
		for (int i = 0; i < rows[0].size(); i++) {
			map<variant<int, double, string>, vector<pair<int, int>>> nodeMap;

			for (int j = 1; j < rows.size(); j++) {

				if (nodeMap.count(rows[j][i]) == 0) {
					vector<pair<int, int>> v1 = { { j,i } };
					nodeMap.insert(std::make_pair(rows[j][i], v1));
				}
				else nodeMap[rows[j][i]].push_back({ j,i });
			}

			for (const auto& [k, v] : nodeMap) {
				Node* newNode = new Node(k, rows[0][i]);
				for (int index = 0; index < v.size(); index++) {

					arr[(v[index].first) - 1][(v[index].second)] = newNode;
				}

			}


		}
		return arr;

	}


	void createTrees(vector<vector<Node*>> nodeRawData) {
		
		
		for (int col = 0; col < nodeRawData.at(0).size(); col++)
		{
			vector<Node*> nodeCol;
			for (int row = 0; row < nodeRawData.size(); row++)
			{
				auto it = find(nodeCol.begin(), nodeCol.end(), nodeRawData[row][col]);

				if (it != nodeCol.end()) {
					continue;
				}
				else {
					nodeCol.push_back(nodeRawData[row][col]);
				}

			}

			Tree* newTree = new Tree();
			newTree->createTree(nodeCol);

			coulmnTrees.push_back(newTree);
		}

		

	}

	Graph* createGraph(vector<vector<Node*>> nodeRawData) {
		Node* node = new Node(2, 5);
		Graph* newGraph = new Graph(node);

		for (int row = 0; row < nodeRawData.size(); row++) {
			Node* prev = nullptr;
			for (int col = 0; col < nodeRawData[0].size(); col++) {
				Node* curr = nodeRawData[row][col];
				if (col == 0) {
					newGraph->indexNode->addOutRelation(row, curr);
					prev = curr;
				}
				else {
					newGraph->insertNode(prev, curr, row);
					prev = curr;
				}
			}
		}

		return newGraph;
	}
	std::vector<std::string> split(const std::string& str) {
		std::stringstream ss(str);
		std::string word;
		std::vector<std::string> words;
		while (ss >> word) {
			words.push_back(word);
		}
		return words;
	}
	variant<int, double, string>  convertRawData(string rawData) {
		double doubleValue;
		int intValue;
		string stringValue;

		variant<int, double, string> convertedData;

		bool isInt = true;
		bool isDouble = false;

		for (int index = 0; index < rawData.length(); index++)
		{
			if (rawData[index] == '.' && !isDouble && isInt)
			{
				isDouble = true;
			}
			else if (!isdigit(rawData[index]))
			{
				isInt = false;
			}


		}

		if (isDouble && isInt) {
			doubleValue = stod(rawData);
			convertedData = doubleValue;
		}
		else if (isInt) {
			intValue = stoi(rawData);
			convertedData = intValue;
		}
		else {
			stringValue = rawData;
			convertedData = stringValue;
		}

		return convertedData;

	}

	Node* findTreeNode(Node* node, variant<int, double, string> data){
		if(node == NULL){
			return NULL;
		}else if(node->getData() == data){
			return node;
		}

		Node* left= findTreeNode(node->getLeft(),data);
		Node* right=findTreeNode(node->getright(),data);

		if (left == NULL)
		{
			return right;
		}else{
			return left;
		}
		
		
	}

	public:
	DataCluster(vector < vector<variant<int, double, string>>> stringNodesVector){

		vector<vector<Node*>> createdNodeVector = createNodes(stringNodesVector);

		graph = createGraph(createdNodeVector);
		createTrees(createdNodeVector);
	}
	vector < vector<Node*>> FindPaths(variant<int, double, string>start, variant<int, double, string>end, variant<int, double, string>startCol, variant<int, double, string>endCol){
		Tree* treeStart=new Tree();
		Tree* treeEnd= new Tree();
		for (int tree = 0; tree < coulmnTrees.size(); tree++) {
			if (coulmnTrees[tree]->getRoot()->getLabel() == startCol)
				treeStart = coulmnTrees[tree];
			else if(coulmnTrees[tree]->getRoot()->getLabel() == endCol)
				treeEnd = coulmnTrees[tree];
		}
		Node* startNode= treeStart->searchTree(treeStart->getRoot(), start);
		Node* endNode= treeEnd->searchTree(treeEnd->getRoot(), end);

		vector<vector<Node*>>result = graph->findRelationship(startNode, endNode);
		// vector < vector<variant<int, double, string>>> res2;
		// for (int i = 0; i < result.size(); i++) {
		// 	vector < variant<int, double, string>> res1;
		// 	for (int j = 0; j < result[i].size(); j++) {
		// 		res1.push_back(result[i][j]->getData());
		// 	}
		// 	res2.push_back(res1);
		// }
		return result;
	}
	
	vector<variant<int, double, string>> searchIF(variant<int, double, string>column, variant<int, double, string> target,int condition) {
		
		Tree* treeSearch = new Tree();
		for (int tree = 0; tree < coulmnTrees.size(); tree++) {
			if (coulmnTrees[tree]->getRoot()->getLabel() == column)
				treeSearch = coulmnTrees[tree];
		}
		vector<variant<int, double, string>>res;
			res = treeSearch->searchIfCondition(treeSearch->getRoot(),target, res,condition);
		
		return res;
	}

	
	vector<vector<variant<int, double, string>>> getConnections(int colIndex, vector<variant<int, double, string>> columns ,variant<int, double, string> data){
		Node* treeHead = coulmnTrees[colIndex]->getRoot();

		Node* tragetNode = findTreeNode(treeHead, data);

		vector<int> allIndexes;


		for (const auto &item : tragetNode->getInMap()) {
        	allIndexes.push_back(item.first);
    	}

		vector<vector<variant<int, double, string>>> searchResult = graph->searchByIndexes(allIndexes,columns);

		return searchResult;



	}
};

