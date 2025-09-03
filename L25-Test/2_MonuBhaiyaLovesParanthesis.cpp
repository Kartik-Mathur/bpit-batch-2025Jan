#include <iostream>
#include <stack>
using namespace std;

int main() {

	stack<int> s;

	int ans = 0;

	char a[100000];
	cin >> a;
	int x = -1;

	for (int i = 0; a[i]; ++i)
	{
		if (a[i] == '(') s.push(i);
		else {
			if (s.empty()) x = i;
			else {
				s.pop();
				if (!s.empty()) ans = max(ans, i - s.top());
				else ans = max(ans, i - x);
			}
		}
	}

	cout << ans << endl;



	return 0;
}
















