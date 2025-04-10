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

void printLLByReference(node* &head) {
	while (head != NULL) {
		cout << head->data << "-->";
		head = head->next;
	}
}

void printLLByValue(node* head) {
	while (head != NULL) {
		cout << head->data << "-->";
		head = head->next;
	}
}


int main() {
	node a, b, c;
	// a, b and c are objects of class node
	a.data = 1;
	b.data = 2;
	c.data = 3;

	a.next = &b;
	b.next = &c;
	c.next = NULL;

	node *head, *tail;
	head = &a;
	tail = &c;

	printLLByReference(head);
	// printLLByValue(head);

	cout << '\n' << &a << endl;
	cout <<  head << endl;






	return 0;
}
















