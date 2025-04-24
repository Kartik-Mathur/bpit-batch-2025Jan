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

void zigZagTraversal(node* root) {
	queue<node*> q;

	q.push(root);
	q.push(NULL);
	vector<vector<int> > v;

	vector<int> temp;

	while (!q.empty()) {
		node* f = q.front();
		q.pop();

		if (f) {
			// cout << f->data << " ";
			temp.push_back(f->data);
			if (f->left) q.push(f->left);
			if (f->right) q.push(f->right);
		}
		else {
			v.push_back(temp);
			temp.clear();

			if (!q.empty()) q.push(NULL);
		}
	}


	for (int i = 0 ; i < v.size(); i ++) {
		if (i % 2) { // Odd hai i
			for (int j = v[i].size() - 1; j >= 0; --j)
			{
				cout << v[i][j] << " ";
			}
		}
		else {
			for (int j = 0; j < v[i].size(); ++j)
			{
				cout << v[i][j] << " ";
			}
		}
		cout << endl;
	}
	cout << endl;

}

int main() {

	node* root = buildTree();

	zigZagTraversal(root);

	return 0;
}
















