#include <iostream>
#include <vector>
using namespace std;

int main() {
	// int a[100];
	int n;
	cin >> n;
	// Run time memory allocation
	// vector<int> a(n); // Number of buckets that i need inside vector
	// or we can do this
	vector<int> a;
	a.reserve(n); // n buckets create kr dega

	for (int i = 0; i < n; ++i)
	{
		a[i] = i + 1;
	}

	for (int i = 0; i < n; ++i)
	{
		cout << a[i] << " ";
	}
	cout << endl;

	return 0;
}
















