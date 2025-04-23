#include <iostream>
using namespace std;

class node {
public:
	int data;
	node* next;
	node(int d) {
		data = d;
		next = NULL;
	}
};


class Stack {
public:
	node* head;

	Stack() {
		head = NULL;
	}

	void push(int d) {
		node* n = new node(d);
		if (!head) {
			head = n;
		}
		else {
			n->next = head;
			head = n;
		}
	}

	void pop() {
		if (!head) return;
		else if (head->next == NULL) { // This means only single node is present
			delete head;
			head = NULL;
		}
		else {
			node* t = head;
			head = head->next;
			delete t;
		}
	}

	int top() {
		return head->data;
	}

	bool empty() {
		return head == NULL;
	}
};

int main() {

	Stack s;


	for (int i = 1; i < 5; ++i)
	{
		s.push(i);
	}

	while (!s.empty()) {
		cout << s.top() << " ";
		s.pop();
	}

	cout << endl;

	return 0;
}
















