#pragma once
#include<stdio.h>
#include<iostream>
#include "Node.h"
#include <vector>
#include<algorithm>
#include<variant>

using namespace std;
class Tree
{   Node* root;
	Node* vectorToBST(vector <Node*> Data, int start, int end) {
	if (start > end) {
		return NULL;
	}
	int middle = (start + end) / 2;

	Data[middle]->setLeft(vectorToBST(Data, start, middle - 1));
	Data[middle]->setRight(vectorToBST(Data, middle + 1, end));
	return Data[middle];
}
	vector<Node*> mergeArrays(vector<Node*> arr1, vector<Node*> arr2) {
		vector<Node*> newArr;
		int i = 0;
		int j = 0;

		while (newArr.size() < (arr1.size() + arr2.size())) {
			if (j >= arr2.size()) {
				newArr.push_back(arr1[i]);
				i++;
			}
			else if (i >= arr1.size()) {
				newArr.push_back(arr2[j]);
				j++;
			}
			else if (arr1[i]->getData() == arr2[j]->getData()) {
				newArr.push_back(arr1[i]);
				newArr.push_back(arr1[i]);
				i += 1;
				j += 1;
			}
			else if (arr1[i]->getData() < arr2[j]->getData()) {
				newArr.push_back(arr1[i]);
				i += 1;
			}
			else {
				newArr.push_back(arr2[j]);
				j += 1;
			}
		}
		return newArr;

	}
	vector<Node*> mergeSort(vector<Node*> arr, int start, int end) {
		if (start == end) {
			vector<Node*> res = { arr[start] };
			return res;
		}
		int middle = (start + end) / 2;
		vector<Node*> left = mergeSort(arr, start, middle);
		vector<Node*> right = mergeSort(arr, middle + 1, end);
		return mergeArrays(left, right);


	}



public:
	Tree(string label,string data) { 
		Node* temp = new Node(label,data);
		root = temp;
	}
	Tree() {
		root = NULL;
	}
	void setRoot(Node* root1) {
		root = root1;
	}
	Node* getRoot() {
		return root;
	}
	Node* createTree(vector <Node*> Data) {
		vector<Node*> sortedVector = mergeSort(Data, 0, Data.size() - 1);
		return (vectorToBST(Data, 0, Data.size() - 1));
		//returns the root of the created tree

	}
	
	Node* searchTree(Node* root, variant<int, double, string> target) {
		if (target > root->getData()) {
			root = searchTree(root->getright(), target);
			return root;

		}
		else if (target < root->getData()) {
			root = searchTree(root->getLeft(), target);
			return root;
		}
		else
			return root;
	}
	

};

