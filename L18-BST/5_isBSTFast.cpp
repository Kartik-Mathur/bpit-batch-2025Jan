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

bool isBST(node* root, int mi = INT_MIN, int mx = INT_MAX) {
	if (!root) return true;

	if (root->data >= mi and root->data <= mx and isBST(root->left, mi, root->data) and
	        isBST(root->right, root->data, mx)) return true;
	else return false;
}

int main() {

	node* root = buildBST();
	if (isBST(root)) cout << "BST\n";
	else cout << "Not a BST\n";


	return 0;
}
















