#include <iostream>
using namespace std;

void mergeArrays(int *a, int *b, int *c, int s, int e) {
	int mid = (s + e) / 2;

	int i = s, j = s, k = mid + 1;
	while (j <= mid and k <= e) {
		if (b[j] < c[k]) a[i++] = b[j++];
		else a[i++] = c[k++];
	}

	while (j <= mid) a[i++] = b[j++];
	while (k <= e) a[i++] = c[k++];
}

void mergeSort(int *a, int s, int e) {
	// base case
	if (s == e) return;

	// recursive
	// 1. Divide
	int b[100005], c[100005];
	int mid = (s + e) / 2;
	// Copy s,mid in array b[]
	for (int i = s; i <= mid; ++i)
	{
		b[i] = a[i];
	}

	for (int i = mid + 1; i <= e; ++i)
	{
		c[i] = a[i];
	}

	// 2. Sort
	mergeSort(b, s, mid);
	mergeSort(c, mid + 1, e);
	// 3. Merge
	mergeArrays(a, b, c, s, e);
}

int main() {
	int a[] = {6, 5, 4, 3, 2, 1};
	int n = sizeof(a) / sizeof(int);

	mergeSort(a, 0, n - 1);
	for (int i = 0; i < n; ++i)
	{
		cout << a[i] << " ";
	}
	cout << endl;


	return 0;
}
















