#include "Tree.h"
int main() {
	vector<Node*> v1(7);
	Node* newNode1 = new Node("neame", 5);
	v1[3] = newNode1;
	
	Node* newNode2 = new Node("neame", 8);
	v1[1] = newNode2;
	Node* newNode3 = new Node("neame", 9);
	v1[2] = newNode3;
	v1[6] = newNode3;
	
	Node* newNode4 = new Node("neame", 11);
	v1[4] = newNode4;
	Node* newNode5 = new Node("neame", 25);
	v1[0] = newNode5;
	Node* newNode6 = new Node("neame", 13);
	v1[5] = newNode6;
	
	Tree* tree = new Tree();
	tree->setRoot(tree->createTree(v1));
	tree->print(tree->getRoot());
}