#include <iostream>
#include <queue>
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


void printRange(node* root, int k1, int k2) {
	if (!root) return;

	if (root->data > k2) { // only go to LST
		printRange(root->left, k1, k2);
	}
	else if (root->data < k1) { // only go to RST
		printRange(root->right, k1, k2);
	}
	else {
		printRange(root->left, k1, k2); // Recursion se k1, k2 range ke elements ko print
		// krwaya
		if (root->data >= k1 and root->data <= k2) {
			cout << root->data << " ";
		}
		printRange(root->right, k1, k2);
	}
}


int main() {
	// Input: 8 3 10 1 6 14 4 7 13 -1
	node* root = buildBST();

	printRange(root, 3, 10);
	cout << endl;


	return 0;
}
















