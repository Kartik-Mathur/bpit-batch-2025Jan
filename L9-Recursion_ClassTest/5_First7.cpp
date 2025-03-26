#include <iostream>
using namespace std;

int first7(int *a, int n) {
	// base case
	if (n == 0) return -1;

	// recursive case
	if (a[0] == 7) return 0;
	int indx = first7(a + 1, n - 1);

	if (indx == -1) return -1;

	return indx + 1;
}

int main() {

	int a[] = {1, 2, 7, 3, 4, 5, 7, 7};
	int n = sizeof(a) / sizeof(int);


	cout << first7(a, n) << endl;

	return 0;
}
















