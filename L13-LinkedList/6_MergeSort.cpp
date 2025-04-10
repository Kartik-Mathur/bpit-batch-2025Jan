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

node* midLL(node* head) {
	if (head == NULL || head->next == NULL) return head;

	node* s = head;
	node* f = head->next;

	while (f and f->next) {
		f = f->next->next;
		s = s->next;
	}

	return s;
}

node* mergeLL(node* a, node* b) {
	if (a == NULL) return b;
	if (!b) return a;

	node* nH;

	if (a->data < b->data) {
		nH = a;
		nH->next = mergeLL(a->next, b);
	}
	else {
		nH = b;
		nH->next = mergeLL(a, b->next);
	}

	return nH;
}

// sort karke merko new head return karna hai
node* mergeSort(node* head) {
	// base case
	if (head == NULL or head->next == NULL) return head;

	// recursive case
	// 1. Divide
	node* m = midLL(head);
	node* a = head;
	node* b = m->next;
	m->next = NULL;
	// 2. Sort
	a = mergeSort(a); // choti list ko sort krke recursion bhi naya head return karega
	b = mergeSort(b); // choti list ko sort krke recursion bhi naya head return karega
	// 3. Merge
	node* nH = mergeLL(a, b);
	// 4. return new head
	return nH;
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

	node* x = mergeSort(head);
	printLL(x);


	return 0;
}
















