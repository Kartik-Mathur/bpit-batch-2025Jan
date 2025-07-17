#include <iostream>
#include <queue> // heap is called priority_queue inside STL
#include <functional>
using namespace std;

void printHeap(priority_queue<int, vector<int>, greater<int> > h) {
	while (!h.empty()) {
		cout << h.top() << " ";
		h.pop();
	}
	cout << endl;
}

int main() {
	priority_queue<int, vector<int>, greater<int> > h; // Minheap
	int k = 3;
	int cs = 0;

	while (-1) {
		int data;
		cin >> data;

		if (data == -1) {
			// print the heap
			printHeap(h);
		}
		else {
			if (cs == k) {
				if (h.top() < data) {
					h.pop(); // Pop krdo minimum ko
					h.push(data);
				}
			}
			else {
				h.push(data);
				cs++;
			}
		}
	}

	return 0;
}
















