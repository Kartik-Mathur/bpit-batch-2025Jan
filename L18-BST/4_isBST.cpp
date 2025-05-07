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

node* insertInBST(node* root, int data) {
	if (!root) {
		root = new node(data);
		return root;
	}

	if (data < root->data) {
		root->left = insertInBST(root->left, data);
	}
	else {
		root->right = insertInBST(root->right, data);
	}
	return root;
}

node* buildBST() {

	node* root = NULL;


	int data;
	cin >> data;
	while (data != -1) {
		root = insertInBST(root, data);

		cin >> data;
	}

	return root;
}


int minTree(node*root) {
	if (!root) return INT_MAX;

	int left = minTree(root->left);
	int right = minTree(root->right);

	return min(root->data, min(left, right));
}

int maxTree(node*root) {
	if (!root) return INT_MIN;

	int left = maxTree(root->left); // LST ka max value bata
	int right = maxTree(root->right);// RST ka max value bata

	return max(root->data, max(left, right));
}

bool isBST(node* root) {
	if (!root) return true;

	int leftMax = maxTree(root->left);
	int rightMin = minTree(root->right);

	if (root->data >= leftMax and root->data <= rightMin and isBST(root->left) and
	        isBST(root->right)) return true;
	else return false;
}

int main() {

	node* root = buildBST();
	if (isBST(root)) cout << "BST\n";
	else cout << "Not a BST\n";


	return 0;
}
















