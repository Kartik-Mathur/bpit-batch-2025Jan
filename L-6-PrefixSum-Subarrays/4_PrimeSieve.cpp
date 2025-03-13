#include <iostream>
using namespace std;

int main() {

	bool a[100005];
	for (int i = 0; i < 100005; ++i)
	{
		a[i] = true;
	}

	int n;
	cin >> n;

	for (int i = 2; i <= n; ++i)
	{
		if (a[i] == true) {
			for (int j = 2 * i; j <= n; j += i)
			{
				a[j] = false;
			}
		}

	}

	for (int i = 2; i <= n; ++i)
	{
		if (a[i]) cout << i << " ";
	}
	cout << endl;

	return 0;
}
















