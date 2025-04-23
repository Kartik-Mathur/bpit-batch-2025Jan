#include <iostream>
#include <stack>
using namespace std;

int main() {

	string str;
	stack<int> s;

	int val = 1;
	int reorder = 0;

	int n; cin >> n;

	for (int i = 0; i < 2 * n; ++i)
	{
		cin >> str;
		if (str == "add") {
			int number; cin >> number;
			s.push(number);
		}
		else {
			if (!s.empty()) {
				if (val == s.top()) {
					s.pop();
				}
				else {
					reorder++;
					s = {}; // make stack empty
				}
			}

			val++;
		}
	}

	cout << reorder << endl;

	return 0;
}
















