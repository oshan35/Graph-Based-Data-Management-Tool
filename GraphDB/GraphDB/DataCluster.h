#pragma once
#include<stdio.h>
#include<iostream>
#include "Node.h"
#include <vector>
#include<algorithm>
#include<variant>

class DataCluster
{
	vector<Node*> tree; // should this be a vector or a map containing trre heads and labels as keys
	Node* graph;
public:
	vector < vector<Node*> createDataBase;
};

