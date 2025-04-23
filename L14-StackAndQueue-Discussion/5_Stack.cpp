#include <iostream>
#include <stack> // STL of stack
using namespace std;

int main() {

	stack<int> s;

	for (int i = 1; i < 5; ++i)
	{
		s.push(i);
	}

	while (!s.empty()) {
		cout << s.top() << " ";
		s.pop();
	}

	cout << endl;

	return 0;
}
















