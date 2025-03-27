#include <iostream>
using namespace std;

void solve(int *a, int i, int n, int *b, int j) {
	// base case
	if (i == n) {
		// print kardo b[] ko, that will include j elements in it
		for (int k = 0; k < j; ++k)
		{
			cout << b[k] << " ";
		}
		cout << endl;
		return;
	}
	// recursive case
	// 1. ith ko mat lo b mei
	solve(a, i + 1, n, b, j);
	// 2. ith ko lelo b[] mei
	b[j] = a[i];
	solve(a, i + 1, n, b, j + 1);
}

int main() {

	int a[] = {1, 2, 3};
	int n = sizeof(a) / sizeof(int);
	int b[200];
	solve(a, 0, n, b, 0);
	return 0;
}
















