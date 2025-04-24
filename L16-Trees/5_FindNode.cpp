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

node* search(node* root, int key) {
	if (!root) return NULL;

	if (root->data == key) return root;

	node* left = search(root->left, key);
	if (left != NULL) return left; // Agar left side se key wali node ka address aa gaya toh done

	node* right = search(root->right, key);
	// if (right != NULL) return right;

	return right; // right se answer aaya toh address hoga, nhi aaya toh usmei NULL hoga
}


int main() {

	node* root = buildTree();

	node* ans = search(root, 113);
	if (ans)cout << "Found: " << ans->data << endl;
	else cout << "Not Found\n";

	return 0;
}
















