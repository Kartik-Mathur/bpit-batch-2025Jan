#include <iostream>
using namespace std;

void printAll7(int *a, int i, int n) {
	// base case
	if (i == n) {
		return;
	}

	// recursive case
	// Ek index par meine check krke index ko print kar diya
	if (a[i] == 7) cout << i << " ";

	// Baaki ke indexes print karne ko recursion ko bol diya
	printAll7(a, i + 1, n);
}

int main() {

	int a[] = {2, 3, 7, 6, 5, 7, 9, 7};
	int n = sizeof(a) / sizeof(int);

	printAll7(a, 0, n);

	return 0;
}
















