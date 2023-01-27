#include "pch.h"
#include "../../GraphDB/GraphDB/Tree.h"
#include<iostream>
using namespace std;
TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);

}
TEST(GraphDBTesting, mergeSrttesting) {
	Tree* tree1 = new Tree();
	Node* node1 = new Node("Weight",1);
	Node* node2 = new Node("Weight", 14);
	Node* node3 = new Node("Weight", 12);
	Node* node4 = new Node("Weight", 67);
	Node* node5 = new Node("Weight", 11);
	Node* node6 = new Node("Weight", 150);
	Node* node7 = new Node("Weight", 15);
	Node* node8 = new Node("Weight", 16);
	vector<Node*> resInput = { node1,node2,node3,node4,node5,node6,node7,node8 };
	
}
TEST(GraphDBTesting, createTreeTesting) {
	Node* node1 = new Node("Weight", 1);
	Node* node2 = new Node("Weight", 14);
	Node* node3 = new Node("Weight", 12);
	Node* node4 = new Node("Weight", 67);
	Node* node5 = new Node("Weight", 11);
	Node* node6 = new Node("Weight", 150);
	Node* node7 = new Node("Weight", 15);
	Node* node8 = new Node("Weight", 16);
	Tree* tree2 = new Tree();
	vector<Node*> resInput = { node1,node2,node3,node4,node5,node6,node7,node8 };
	
	Node* resroot = tree2->createTree(resInput);
	EXPECT_EQ(node2, resroot);
	tree2->setRoot(tree2->createTree(resInput));
	EXPECT_EQ(node6, tree2->searchTree(tree2->getRoot(), 150));
	
}