#include <iostream>
using namespace std;

void bubbleSort(int *a, int n) {

	for (int i = 0; i < n - 1; ++i)
	{
		for (int j = 0; j < n - 1 - i; ++j)
		{
			if (a[j] > a[j + 1]) {
				swap(a[j], a[j + 1]);
			}
		}
	}
}

void solve(int *a, int n, int i) {
	// base case
	if (i == n - 1) return;

	// recursive case
	// Pehle number ko sahi jagah rakhdo, baaki ka kaam recursion ko boldenge
	for (int j = 0; j < n - 1 - i; ++j)
	{
		if (a[j] > a[j + 1]) {
			swap(a[j], a[j + 1]);
		}
	}

	// Ab baaki ke numbers ko sahi jagah recursion se rakhwa do
	solve(a, n, i + 1); // Assumption hai ki recursion kaam kr dega
}

void solve1(int *a, int n, int i, int j) {
	// base case
	if (i == n - 1) return;

	// recursive case

	// Ab baaki ke numbers ko sahi jagah recursion se rakhwa do
	if (j == n - 1 - i)
		solve1(a, n, i + 1, 0); // Assumption hai ki recursion kaam kr dega
	else {
		if (a[j] > a[j + 1]) {
			swap(a[j], a[j + 1]);
		}

		solve1(a, n, i, j + 1); // J ka loop chal raha hai
	}
}

int main() {

	int a[] = {5, 4, 3, 2, 1};
	int n = sizeof(a) / sizeof(int);

	solve1(a, n, 0, 0);

	for (int i = 0; i < n; ++i)
	{
		cout << a[i] << " ";
	}



	return 0;
}
















