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

int height(node*root) {
	if (!root) return 0;

	return 1 + max(height(root->left), height(root->right));
}

int main() {

	node* root = buildTree();
	cout << height(root) << endl;

	return 0;
}
















