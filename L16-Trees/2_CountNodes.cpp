#include <iostream>
using namespace std;

class node {
public:
	int data;
	node* left, *right;
	node(int d) {
		data = d;
		left = right = NULL;
	}
};

node* buildTree() {
	int data;
	cin >> data;
	if (data == -1) return NULL;

	node* root = new node(data);
	// LST
	root->left = buildTree();
	// RST
	root->right = buildTree();

	return root;
}

int countNodes(node*root) {
	if (!root) return 0;

	return 1 + countNodes(root->left) + countNodes(root->right);
}

int main() {

	node* root = buildTree();
	cout << countNodes(root) << endl;

	return 0;
}
















