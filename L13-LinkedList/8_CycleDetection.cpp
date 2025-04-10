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

void breakTheCycle(node* head, node* f) {
	node* s = head;

	node* fp = head;
	while (fp->next != f) {
		fp = fp->next;
	}

	while (f != s) {
		fp = f;
		f = f->next;
		s = s->next;
	}
	fp->next = NULL;
}

bool isCyclic(node* head) {
	node* f = head, *s = head;

	while (f and f->next) {
		f = f->next->next;
		s = s->next;

		if (f == s) {
			breakTheCycle(head, f);
			return true;
		}
	}

	return false;
}


int main() {

	node* head, *tail;
	head = tail = NULL;

	insertAtEnd(head, tail, 1);
	insertAtEnd(head, tail, 2);
	insertAtEnd(head, tail, 3);
	insertAtEnd(head, tail, 4);
	insertAtEnd(head, tail, 5);
	insertAtEnd(head, tail, 6);
	insertAtEnd(head, tail, 7);
	insertAtEnd(head, tail, 8);

	printLL(head);

	tail->next = head->next->next->next;


	if (isCyclic(head)) cout << "Cyclic\n";
	else cout << "Not Cyclic\n";

	printLL(head);



	return 0;
}
















