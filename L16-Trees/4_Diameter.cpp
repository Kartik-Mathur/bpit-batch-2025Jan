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

int diameter(node* root) {
	if (!root) return 0;

	int op1 = height(root->left) + height(root->right);
	int op2 = diameter(root->left);
	int op3 = diameter(root->right);

	return max(op1, max(op2, op3));
}


class Pair {
public:
	int height;
	int diameter;
};

Pair fastDiameter(node* root) {
	if (!root) {
		Pair p;
		p.height = p.diameter = 0;
		return p;
	}

	Pair p;
	Pair left = fastDiameter(root->left);
	Pair right = fastDiameter(root->right);

	p.height = max(left.height, right.height) + 1;
	int op1 = left.height + right.height;
	int op2 = left.diameter;
	int op3 = right.diameter;

	p.diameter = max(op1, max(op2, op3));
	return p;
}

int main() {

	node* root = buildTree();
	cout << diameter(root) << endl;

	Pair p = fastDiameter(root);
	cout << "Fast Height   " << p.height << endl;
	cout << "Fast Diameter " << p.diameter << endl;

	return 0;
}
















