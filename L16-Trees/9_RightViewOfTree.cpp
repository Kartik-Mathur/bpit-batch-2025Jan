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

void rightViewTree(node* root, int l, int &maxLevel) {
	if (!root) return;

	if (l > maxLevel) {
		cout << root->data << " ";
		maxLevel = l;
	}

	rightViewTree(root->right, l + 1, maxLevel);
	rightViewTree(root->left, l + 1, maxLevel);
}


void leftViewTree(node* root, int l, int &maxLevel) {
	if (!root) return;

	if (l > maxLevel) {
		cout << root->data << " ";
		maxLevel = l;
	}

	leftViewTree(root->left, l + 1, maxLevel);
	leftViewTree(root->right, l + 1, maxLevel);
}


int main() {

	node* root = buildTree();
	int maxLevel = -1;
	leftViewTree(root, 0, maxLevel);

	return 0;
}
















