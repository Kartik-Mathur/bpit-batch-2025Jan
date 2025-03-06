#include <iostream>
using namespace std;

int searchRotated(int *a, int n, int key) {
	int s = 0, e = n - 1;

	while (s <= e) {
		int mid = (s + e) / 2;

		if (a[mid] == key) return mid;
		else if (a[s] <= a[mid]) {
			if (key >= a[s] and key <= a[mid]) e = mid - 1;
			else s = mid + 1;
		}
		else {
			if (key >= a[mid] and key <= a[e]) s = mid + 1;
			else e = mid - 1;
		}
	}

	return -1;
}

int main() {
	int a[] = {7, 8, 10, 11, 15, 0, 1, 3, 4, 5};
	int n = sizeof(a) / sizeof(int);

	cout << searchRotated(a, n, 15) << endl;




	return 0;
}
















