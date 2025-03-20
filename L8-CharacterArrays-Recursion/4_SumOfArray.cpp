#include <iostream>
using namespace std;

int sumOfArray(int *a, int n) {
	if (n == 0) return 0;

	return a[0] + sumOfArray(a + 1, n - 1);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int a[] = {1, 2, 3, 4, 5};
	int n = sizeof(a) / sizeof(int);

	cout << sumOfArray(a, n) << endl;

	return 0;
}
















