#include <iostream>
using namespace std;

int main() {

	int a[] = {1, 2, 3, 4, 5};
	int n = sizeof(a) / sizeof(int); // 5

	int left[100];
	int right[100];
	int res[100];
	for (int i = 0; i < n; ++i)
	{
		res[i] = 1;
	}

	// res ke andar hi products ko calculate karte hai for every index i
	// res[i] : a[0]*a[1]*a[2]* . . . . * a[i-1]

	res[0] = 1;// because 0th index se pehle koi element hai hi nhi
	int ans = a[0];
	for (int i = 1; i < n; ++i)
	{
		res[i] = ans;
		ans *= a[i];
	}

	// Right side ke products ko calculate karte hai for every index i and multiply kardo
	// res ke array ke andar hi
	// right[i] : a[i+1]*a[i+2]* . . . . * a[n-1]

	// right[n - 1] = 1;
	ans = a[n - 1];
	for (int i = n - 2; i >= 0; --i)
	{
		res[i] *= ans;
		ans *= a[i];
	}

	for (int i = 0; i < n; ++i)
	{
		cout << res[i] << " ";
	}
	cout << endl;

	return 0;
}
















