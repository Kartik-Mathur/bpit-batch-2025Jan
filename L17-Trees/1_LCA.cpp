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

node* lca(node* root, int a, int b) {
	if (!root) return NULL;

	if (root->data == a || root->data == b) return root;
	node* leftMeiNodeKaAddress = lca(root->left, a, b);
	node* rightMeiNodeKaAddress = lca(root->right, a, b);

	if (leftMeiNodeKaAddress and rightMeiNodeKaAddress) return root;
	else if (leftMeiNodeKaAddress) return leftMeiNodeKaAddress;
	return rightMeiNodeKaAddress;
}

int main() {

	node* root = buildTree();
	node* ans = lca(root, 3, 13);

	if (ans) cout << ans->data << endl;
	else cout << "No LCA possible\n";


	return 0;
}
















