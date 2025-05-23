#include <iostream>
using namespace std;

double median(int *a, int *b, int n, int m) {

	if (n > m) return median(b, a, m, n);

	int s = 0, e = n;

	while (s <= e) {

		int mid = (s + e) / 2; // Parition in a[]: Yaha tak left mei jaenge elements a[]
		int mid1 = (n + m + 1) / 2 - mid; // Parition in b[]:Yaha tak left mei jaenge elements b[]

		int leftMaxa = (mid - 1 >= 0) ? a[mid - 1] : INT_MIN ;
		int leftMaxb = (mid1 - 1 >= 0) ? b[mid1 - 1] : INT_MIN;
		int rightMina = (mid < n) ? a[mid] : INT_MAX;
		int rightMinb = (mid1 < m) ? b[mid1] : INT_MAX;

		if (leftMaxa < rightMinb and leftMaxb < rightMina) {
			if ((n + m) % 2 == 1) return max(leftMaxa, leftMaxb);
			else return (max(leftMaxa, leftMaxb) + min(rightMina, rightMinb)) / 2.0;
		}
		else if (leftMaxa > rightMinb) e = mid - 1;
		else s = mid + 1;
	}
	return 0;
}


int main() {

	int a[] = {1, 4, 7, 9, 11};
	int b[] = {2, 3, 5, 6, 8, 10};

	int n = sizeof(a) / sizeof(int);
	int m = sizeof(b) / sizeof(int);

	cout << median(a, b, n, m) << endl;

	return 0;
}
















