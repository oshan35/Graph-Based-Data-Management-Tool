

#include <iostream>
#include <string>

#include <sstream>

/*void increseData(Tree* tree) {
	tree->getRoot()->getLeft()->updateData(1220);

}
void printtreenode(Node* root)
{
	if (root == NULL)
		return;
	
	printtreenode(root->getLeft());
	
	printtreenode(root->getright());
}
string stringify(variant<int, double, string> const& value) {
	if (int const* pval = std::get_if<int>(&value))
		return to_string(*pval);

	if (double const* pval = std::get_if<double>(&value))
		return to_string(*pval);

	return get<string>(value);
}


int main() {
	Node* node1 = new Node("Weight", 1);
	Node* node2 = new Node("Weight", 14);
	Node* node3 = new Node("Weight", 12);
	Node* node4 = new Node("Weight", 67);
	Node* node5 = new Node("Weight", 11);
	Node* node6 = new Node("Weight", 150);
	Node* node7 = new Node("Weight", 15);
	Node* node8 = new Node("Weight", 16);


	Tree* tree = new Tree();
	tree->setRoot(node1);
	tree->getRoot()->setLeft(node2);
	tree->getRoot()->setRight(node3);
	tree->getRoot()->getright()->setLeft(node4);
	tree->getRoot()->getright()->setRight(node5);
	Node* curr = tree->getRoot();
	printtreenode(curr);
	
}
*/
// C++ program to print nodes of extreme corners
// of each level in alternate order

/*
using namespace std;

// A binary tree node
struct Node {
	int data;
	Node* left, * right;
};

// Utility function to allocate memory for a new node
Node* newNode(int data)
{
	Node* node = new (Node);
	node->data = data;
	node->left = node->right = NULL;
	return (node);
}

// Function that returns the height of the binary tree
int height(Node* root)
{
	if (root == NULL)
		return 0;

	int lheight = height(root->left);
	int rheight = height(root->right);

	return max(lheight, rheight) + 1;
}

// Function performs level order traversal from right to
// left and prints the first node during the traversal
void rightToLeft(Node* root, int level, int& f)
{
	if (root == NULL)
		return;

	// Checks for the value of f so that
	// only first node is printed during
	// the traversal and no other node is printed
	if (level == 1 && f == 0) {
		printf("%d ", root->data);
		f = 1;
	}

	else if (level > 1) {
		rightToLeft(root->right, level - 1, f);
		rightToLeft(root->left, level - 1, f);
	}
}

// Function performs level order traversal from left to
// right and prints the first node during the traversal
void leftToRight(Node* root, int level, int& f)
{
	if (root == NULL)
		return;

	// Checks for the value of f so that
	// only first node is printed during
	// the traversal and no other node is printed
	if (level == 1 && f == 1) {
		printf("%d ", root->data);
		f = 0;
	}

	else if (level > 1) {
		leftToRight(root->left, level - 1, f);
		leftToRight(root->right, level - 1, f);
	}
}

// Function to print the extreme nodes of
// a given binary tree
void printExtremeNodes(Node* root)
{
	// Stores height of binary tree
	int h = height(root);

	// Flag to mark the change in level
	int flag = 0;

	// To check if the extreme node of a
	// particular level has been visited
	int f = 0;

	for (int i = 1; i <= h; i++) {
		// If flag is zero then traverse from
		// right to left at the given level and
		// print the first node during the traversal
		if (flag == 0) {
			rightToLeft(root, i, f);
			flag = 1;
		}

		// If flag is one then traverse from
		// left to right at the given level and
		// print the first node during the traversal
		else if (flag == 1) {
			leftToRight(root, i, f);
			flag = 0;
		}
	}

	return;
}

// Driver code
int main()
{
	Node* root = newNode(1);

	root->left = newNode(2);
	root->right = newNode(3);

	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->right->right = newNode(7);

	root->left->left->left = newNode(8);
	root->left->left->right = newNode(9);
	root->left->right->left = newNode(10);
	root->left->right->right = newNode(11);
	root->right->right->left = newNode(14);
	root->right->right->right = newNode(15);

	root->left->left->left->left = newNode(16);
	root->left->left->left->right = newNode(17);
	root->right->right->right->right = newNode(31);

	printExtremeNodes(root);

	return 0;
}
*/
#include "Graph.h"
#include <iostream>
#include <sstream>
using namespace std;
struct make_string_functor {
	std::string operator()(const std::string& x) const { return x; }
	std::string operator()(int x) const { return std::to_string(x); }
};
int main() {
	Node* node1 = new Node("Name", "Nehara");
	Node* node2 = new Node("Name", "Dahami");
	Node* node3 = new Node("Name", "Oshan");
	Node* node4 = new Node("Name", "Ashen");
	Node* node5 = new Node("District", "Matara");
	Node* node6 = new Node("District", "Gampaha");
	Node* node7 = new Node("age", 22);
	Node* node8 = new Node("age", 23);
	Node* node9 = new Node("Uni", "Ruhuna");
	Node* node10 = new Node("Education", "Ruhuna");
	Node* node11 = new Node("Degree", "Engineering");
	Graph* graph = new Graph(node11);
	graph->insertNode(node9, node10, 1);
	graph->insertNode(node9, node10, 2);
	graph->insertNode(node9, node10, 3);
	graph->insertNode(node9, node10, 4);
	graph->insertNode(node8, node9, 3);
	graph->insertNode(node8, node9, 4);
	graph->insertNode(node7, node9, 1);
	graph->insertNode(node7, node9, 2);
	graph->insertNode(node3, node8, 4);
	graph->insertNode(node4, node8, 3);
	graph->insertNode(node1, node7, 1);
	graph->insertNode(node2, node7,2);
	graph->insertNode(node5, node1, 1);
	graph->insertNode(node5, node2, 2);
	graph->insertNode(node5, node4, 3);
	graph->insertNode(node6, node3, 4);
	graph->insertNode(node11, node5, 1);
	graph->insertNode(node11, node5, 2);
	graph->insertNode(node11, node5, 3);
	graph->insertNode(node11, node6, 4);	
	/*
	for (const auto& [key, value] : node10->getInMap()) {
		std::cout << std::visit(make_string_functor(), value->getData()) << "\n";
	}
	*/
	vector<vector<Node*>> res;
	vector<Node*>input;
	vector<vector<Node*>> res_got = graph->findInPath(node7, node5, res, input, 0);
	if (res_got.empty()) {
		res_got= graph->findOutPath(node11, node9, res, input, 0);
	}
	
	for (int i = 0; i < res_got.size(); i++) {
		for (int j = 0; j < res_got[i].size(); j++) {


			std::cout << std::visit(make_string_functor(), res_got[i][j]->getData()) << "\n";
		}
		cout << endl;
	}
	return 0;
	
}