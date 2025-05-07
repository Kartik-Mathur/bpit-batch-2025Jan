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

node* search(node* root, int key) {
	if (!root) return NULL;

	if (root->data == key) return root;
	else if (root -> data < key) {
		node*ans = search(root->right, key); // RST se pucha ki key hai ya nhi batao
		return ans;
	}
	else {
		return search(root->left, key);
	}
}

int main() {
	// Input: 8 3 10 1 6 14 4 7 13 -1
	node* root = buildBST();

	node* ans = search(root, 100);
	if (ans) cout << ans->data << " ";
	else cout << "Not Found\n";


	return 0;
}
















