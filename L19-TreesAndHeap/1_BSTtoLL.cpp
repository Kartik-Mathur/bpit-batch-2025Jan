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

class LinkedList {
public:
	node* head, *tail;
};

LinkedList bstToLL(node* root) {
	if (!root) {
		return {NULL, NULL};
	}

	// Recursive case
	if (root->left and root->right) { // LST and RST both exists
		LinkedList left = bstToLL(root->left); // LST to LL FROM RECURSION
		LinkedList right = bstToLL(root->right); // RST to LL FROM RECURSION
		left.tail->right = root;
		root->right = right.head;

		return {left.head, right.tail};
	}
	else if (root->left and !root->right) { // LST exist and RST doesn't exist
		LinkedList left = bstToLL(root->left); // LST to LL FROM RECURSION
		left.tail->right = root;
		return {left.head, root};
	}
	else if (!root->left and root->right) { // LST doesn't exist and RST exist
		LinkedList right = bstToLL(root->right); // RST to LL FROM RECURSION
		root->right = right.head;

		return {root, right.tail};
	}
	else {
		// LinkedList l;
		// l.head = l.tail = root;
		return {root, root};
	}
}

int main() {

	node* root = buildBST();

	LinkedList ans = bstToLL(root);

	node* head = ans.head;
	while (head) {
		cout << head->data << " --> ";
		head = head->right;
	} cout << "NULL\n";

	return 0;
}
















