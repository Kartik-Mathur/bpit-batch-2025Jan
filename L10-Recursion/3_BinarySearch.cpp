#include <iostream>
using namespace std;

int binarySearch(int *a, int s, int e, int key) {
	// base case
	if (s > e) return -1;

	// recursive case
	int mid = (s + e) / 2;
	if (a[mid] == key) return mid;
	else if (key > a[mid]) {
		int indx = binarySearch(a, mid + 1, e, key);
		return indx;
	}
	else {
		return binarySearch(a, s, mid - 1, key);
	}
}

int main() {

	int a[] = {1, 2, 3, 4, 5};
	int n = sizeof(a) / sizeof(int);
	int key = 10;

	cout << binarySearch(a, 0, n - 1, key) << endl;

	return 0;
}
















