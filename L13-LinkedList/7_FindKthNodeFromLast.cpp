#include <iostream>
using namespace std;

class node {
public:
	int data;
	node* next;
	node(int d) { // Node banani hai toh constructor se banwaenge
		data = d;
		next = NULL;
	}
};

int lengthLL(node* head) {
	int cnt = 0;
	while (head != NULL) {
		cnt++;

		head = head->next;
	}

	return cnt;
}

void printLL(node* head) {
	while (head != NULL) {
		cout << head->data << "-->";
		head = head->next;
	}
	cout << "NULL\n";
}

void insertAtEnd(node* &head, node* &tail, int data) {
	if (head == NULL) {
		node* n = new node(data);
		head = tail = n;
	}
	else {
		node* n = new node(data);
		tail->next = n;
		tail = n;
	}
}

node* findKLast(node* head, int k) {
	node* s = head, *f = head;

	for (int i = 0; i < k; ++i)
	{
		f = f->next;
	}

	while (f != NULL) {
		f = f->next;
		s = s->next;
	}

	return s;
}

int main() {

	node* head, *tail;
	head = tail = NULL;

	insertAtEnd(head, tail, 11);
	insertAtEnd(head, tail, 3);
	insertAtEnd(head, tail, 51);
	insertAtEnd(head, tail, 7);
	insertAtEnd(head, tail, 2);
	insertAtEnd(head, tail, 1);
	printLL(head);

	node* x = findKLast(head, 4);
	cout << x->data << endl;


	return 0;
}
















