#include <iostream>
using namespace std;

int sum(int n) {
	if (n == 0) return 0;

	return n + sum(n - 1);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	cout << sum(5);

	return 0;
}
















