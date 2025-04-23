#include <iostream>
#include <stack>
using namespace std;


int main() {

	stack<int> s;

	int a[] = {6, 2, 1, 3, 4, 4, 7};
	int n = sizeof(a) / sizeof(int);

	int nextSmaller[100];

	for (int i = 0; i < n; ++i)
	{
		while (!s.empty() and a[i] < a[s.top()]) {
			nextSmaller[s.top()] = i;
			s.pop();
		}

		s.push(i);
	}

	while (!s.empty()) {
		nextSmaller[s.top()] = n;
		s.pop();
	}

	for (int i = 0; i < n; ++i)
	{
		cout << nextSmaller[i] << " ";
	}
	cout << endl;


	return 0;
}
















