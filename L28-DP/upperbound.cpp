#include <iostream>
using namespace std;

int main() {

	int a[] = {1, 2, 2, 2, 3, 5};
	int n = sizeof(a) / sizeof(int);

	cout << *upper_bound(a, a + n, 2) << endl;
	int *x = upper_bound(a, a + n, 4);
	*x = 100;
	for (int i = 0; i < n; ++i)
	{
		cout << a[i] << " ";
	}
	cout << endl;


	return 0;
}
















