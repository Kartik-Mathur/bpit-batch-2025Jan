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

node* buildLevelWiseTree() {

	int data;
	cout << "Enter root data : ";
	cin >> data;
	if (data == -1) return NULL;

	node* root = new node(data);
	queue<node*> q;
	q.push(root);

	// Take input of tree
	while (!q.empty()) {
		node* f = q.front();
		q.pop();

		cout << "Enter children of " << f->data << " : ";
		int l, r;
		cin >> l >> r;
		if (l != -1) f->left = new node(l), q.push(f->left);
		if (r != -1) f->right = new node(r), q.push(f->right);
	}


	return root;
}


void levelOrderPrint(node* root) {
	queue<node*> q;

	q.push(root);
	q.push(NULL);

	while (!q.empty()) {
		node* f = q.front();
		q.pop();

		if (f) {
			cout << f->data << " ";
			if (f->left) q.push(f->left);
			if (f->right) q.push(f->right);
		}
		else {
			cout << endl;
			if (!q.empty()) q.push(NULL);
		}
	}
}


int main() {

	node* root = buildLevelWiseTree();

	levelOrderPrint(root);

	return 0;
}
















