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

void preOrder(node* root) {
	if (!root) return;

	cout << root->data << " ";
	preOrder(root->left);
	preOrder(root->right);
}


void inorder(node* root) {
	if (!root) return;

	inorder(root->left);
	cout << root->data << " ";
	inorder(root->right);
}


void postOrder(node* root) {
	if (!root) return;

	postOrder(root->left);
	postOrder(root->right);
	cout << root->data << " ";
}


int main() {

	node* root = buildTree();
	preOrder(root);
	cout << endl;
	inorder(root);
	cout << endl;
	postOrder(root);
	cout << endl;


	return 0;
}
















