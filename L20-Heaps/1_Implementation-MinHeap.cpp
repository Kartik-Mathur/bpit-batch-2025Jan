#include <iostream>
#include <vector>
using namespace std;

class Minheap
{
	vector<int> v; // Private because we are not suppose to check any other
	// element than min incase of minHeap.
	void heapify(int i) {
		int left = 2 * i;
		int right = 2 * i + 1;

		int mi = i;
		if (left<v.size() and v[mi] > v[left]) mi = left;
		if (right<v.size() and v[mi] > v[right]) mi = right;

		if (mi != i) {
			swap(v[mi], v[i]);
			heapify(mi);
		}
	}

public:
	Minheap() {
		v.push_back(-1); // 0th index ko use nahi krna
	}

	void push(int d) {
		v.push_back(d);
		int c = v.size() - 1;
		int p = c / 2;
		while (p > 0 and v[p] > v[c]) {
			swap(v[p], v[c]);
			c = p;
			p /= 2;
		}
	}

	void pop() {
		swap(v[1], v[v.size() - 1]);
		v.pop_back();

		heapify(1);
	}

	bool empty() {
		return v.size() == 1;
	}

	int top() {
		return v[1];
	}
};

int main() {

	Minheap h; // heap sort

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
















