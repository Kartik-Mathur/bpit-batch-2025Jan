#include <iostream>
using namespace std;

int stringToInt(char *a, int n) {
	// base case
	if (n == 0) return 0;
	// recursive case
	return stringToInt(a, n - 1) * 10 + (a[n - 1] - '0');
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	char a[] = "1234";
	int x = stringToInt(a, strlen(a));

	cout << x + 1 << endl; // 1235
	return 0;
}
















