#include <iostream>
using namespace std;

int main() {

	int a[] = {1, 2, 3, 4, 5};
	int n = sizeof(a) / sizeof(int);

	int key = 41;
	int i;

	for (i = 0; i < n; ++i)
	{
		if (a[i] == key) {
			cout << "Found at index: " << i << endl;
			break;
		}
	}

	if (i == n) cout << "Key not found\n";



	/*
		// Error dega that break cannot be used inside if
		if (n > 0) {
			break;
		}

	*/

	return 0;
}
















