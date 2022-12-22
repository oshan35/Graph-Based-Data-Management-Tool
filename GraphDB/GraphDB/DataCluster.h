#pragma once
#include<stdio.h>
#include<iostream>
#include "Node.h"
#include <vector>
#include<algorithm>
#include<variant>

#include<vector>
#include<iostream>
#include "Node.h"
#include<variant>
#include <map>
using namespace std;
class DataCluster
{
	vector<Node*> tree;
	Node* graph;

	vector<vector<Node*>> createNodes(vector < vector<variant<int, double, string>>> rows, vector<string> firstrow) {// should first row be given seperately
		for (int i = 0; i < rows[0].size(); i++) {
			map<variant<int, double, string>, vector<pair<int, int>>> nodeMap;

			for (int j = 0; j < rows.size(); j++) {

				if (nodeMap.count(rows[j][i]) == 0) {
					vector<pair<int, int>> v1 = { { j,i } };
					nodeMap.insert(std::make_pair(rows[j][i], v1));
				}
				else nodeMap[rows[j][i]].push_back({ j,i });
			}
			vector<vector<Node*> > arr(rows.size(), vector<Node*>(rows[0].size()));

			for (const auto& [k, v] : nodeMap) {
				for (int index = 0; index < v.size(); index++) {
					Node* newNode = new Node(firstrow[i], k);
					arr[v[index].first][v[index].second] = newNode;
				}
				return arr;
			}
		}
	}
public:

};

