#include <iostream>
#include <algorithm>
// #include <functional> // For greater<int>()
using namespace std;

bool meraComparator(int a, int b) {
	return a < b;
}

int main() {

	int a[] = {6, 5, 9, 2, 3, 0, 1};
	int n = sizeof(a) / sizeof(int);

	// sort(begining_address, ending_address);
	// sort(a, a + n, greater<int>());
	sort(a, a + n, meraComparator);
	// sort(a, a + n, [&](int a, int b) {
	// 	return a > b;
	// });

	for (int i = 0; i < n; ++i)
	{
		cout << a[i] << " ";
	}


	return 0;
}
















