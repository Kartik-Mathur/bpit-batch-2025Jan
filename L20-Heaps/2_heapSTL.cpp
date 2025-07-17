#include <iostream>
#include <queue> // heap is called priority_queue inside STL
#include <functional>
using namespace std;

class myClass {
public:
	bool operator() (int a, int b) { // Functor
		return a < b;
	}
};

int main() {

	// priority_queue<int> h; // Maxheap
	// priority_queue<int, vector<int>, less<int> > h; // Maxheap
	// priority_queue<int, vector<int>, greater<int> > h; // Minheap
	priority_queue<int, vector<int>, myClass > h;

	h.push(1);
	h.push(3);
	h.push(2);
	h.push(4);

	while (!h.empty()) {
		cout << h.top() << endl;
		h.pop();
	}

	return 0;
}
















