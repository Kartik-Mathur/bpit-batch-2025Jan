#include <iostream>
#include <stack>
using namespace std;

int main() {

	stack<int> s;

	int a[] = {6, 2, 1, 3, 4, 4, 7};
	int n = sizeof(a) / sizeof(int);

	int previousGreater[100];

	for (int i = n - 1; i >= 0; --i)
	{
		while (!s.empty() and a[i] > a[s.top()]) {
			previousGreater[s.top()] = i;
			s.pop();
		}

		s.push(i);
	}

	while (!s.empty()) {
		previousGreater[s.top()] = -1;
		s.pop();
	}

	for (int i = 0; i < n; ++i)
	{
		cout << previousGreater[i] << " ";
	}
	cout << endl;


	return 0;
}
















