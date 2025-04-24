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

void mirror(node* root) {
	if (!root) return;

	swap(root->left, root->right);
	mirror(root->left); // LST ka kaam recursion ko boldo
	mirror(root->right); // RST ka kaam recursion ko boldo
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


int main() {

	node* root = buildTree();
	mirror(root);
	preOrder(root);
	cout << endl;
	inorder(root);
	cout << endl;

	return 0;
}
















