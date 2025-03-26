#include <iostream>
using namespace std;

// n is number of elements
int last7(int *a, int n) {
	// base case
	if (n == 0) return -1;

	// recursive case
	if (a[n - 1] == 7) return n - 1;

	return last7(a, n - 1);
}

int main() {

	int a[] = {4, 5, 7, 7, 2, 3};
	int n = sizeof(a) / sizeof(int);

	cout << last7(a, n) << endl;

	return 0;
}
















