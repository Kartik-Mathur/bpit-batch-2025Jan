#include <iostream>
using namespace std;

class Queue {
public:
	int *a;
	int n;
	int cs;
	int f , r;
	Queue(int N) {
		n = N;
		a = new int[n];
		f = 0;
		r = n - 1;
		cs = 0;
	}

	void push(int d) {
		if (cs < n) {
			r = (r + 1) % n;
			a[r] = d;
			cs++;
		}
		else cout << "Overflow\n";
	}

	void pop() {
		if (cs > 0) {
			f = (f + 1) % n;
			cs--;
		}
		else cout << "Undeflow\n";
	}

	bool empty() {
		return cs == 0;
	}

	int front() {
		return a[f];
	}
};

int main() {
	Queue q(4);
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	q.push(5);

	while (!q.empty()) {
		cout << q.front() << " ";
		q.pop();
	}

	q.pop();



	return 0;
}
















