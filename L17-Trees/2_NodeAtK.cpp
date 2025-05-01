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

void solve(node* root, int k, int d = 0) {
	if (!root) return ;

	if (d == k) {
		cout << root->data << " ";
		return;
	}

	solve(root->left, k, d + 1);
	solve(root->right, k, d + 1);
}

int distanceOfNode(node* root, int node, int k) {
	if (!root) return -1;

	if (root->data == node) {
		solve(root, k); // Agar node mill gai toh tree ke neeche wale sabhi nodes at
		//  distance k print karo
		return 0;
	}

	// LST ki root se node ka distance batao
	int d = distanceOfNode(root->left, node, k);
	if (d != -1) { // Valid distance hai
		if (d + 1 == k) {
			cout << root->data << " ";
			return -1; // Ab aur upar distance k par nodes nahi milengi
		}

		int rd = k - d - 2;
		solve(root->right, rd); // Ab right subtree par rd distance wali nodes print kardo
		return d + 1;
	}

	// Ab RST se node ka distance pucho
	d = distanceOfNode(root->right, node, k);
	if (d != -1) {
		if (d + 1 == k) {
			cout << root->data << " ";
			return -1; // Ab aur upar distance k par nodes nahi milengi
		}

		int rd = k - d - 2;
		solve(root->left, rd); // Ab left subtree par rd distance wali nodes print kardo
		return d + 1;
	}

	return -1;
}

int main() {

	node* root = buildTree();

	distanceOfNode(root, 10, 2);


	return 0;
}
















