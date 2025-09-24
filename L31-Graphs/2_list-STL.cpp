#include <iostream>
#include <list> // DOUBLY LINKED LIST
#include <forward_list> // SINGLY LINKED LIST
using namespace std;
void printLL(list<int> &l) {
	for (int d : l) {
		cout << d << "<-->";
	}
	cout << "NULL\n";
}

int main() {

	// forward_list<int> l; // SINGLY LL
	list<int> l; // DOUBLY LL

	l.push_front(1);
	l.push_front(2);
	l.push_front(3);
	l.push_front(4);
	l.push_back(5);
	l.push_back(6);
	l.push_back(7);

	int pos = 4;
	int data = 100;
	// l.insert(address, data);
	// list<int>:: iterator it = l.begin();
	auto it = l.begin(); // Initialisation is must when we use auto keyword
	for (int i = 0; i < pos - 1; ++i)
	{
		it++;
	}
	l.insert(it, data);

	// ANOTHER WAY TO ITERATOR OVER LL
	for (it = l.begin(); it != l.end(); ++it)
	{
		cout << *it << "<-->";
	}
	cout << endl;

	// FOR EACH LOOP
	// For every data d that belongs to linked list-> l
	for (int d : l) {
		cout << d << "<-->";
	}
	cout << "NULL\n";

	// TO print linked list from tail to head
	// for (list<int>::reverse_iterator it = l.rbegin(); it != l.rend(); ++it)
	for (auto it = l.rbegin(); it != l.rend(); ++it)
	{
		cout << *it << "<-->";
	}
	cout << endl;




	// REVERSE A LL
	list<int> l1 = l; // COPY CONSTRUCTOR
	cout << "Linked list before reverse: ";
	printLL(l1);
	l1.reverse();
	cout << "Linked list after reverse: ";
	printLL(l1);


	// SEARCH LL
	auto ans = find(l.begin(), l.end(), 100);
	if (ans != l.end()) {
		cout << "FOUND " << *ans << endl;
	}
	else {
		cout << "NOT FOUND\n";
	}

	// DELETION IN LL
	l1.pop_front();
	printLL(l1);
	l1.pop_back();
	printLL(l1);

	data = 100;
	for (it = l1.begin(); it != l1.end(); ++it)
	{
		if (*it == data) {
			break;
		}
	}

	l1.erase(it);
	printLL(l1);


	// SORT LL
	l1.sort();
	printLL(l1);

	return 0;
}
















