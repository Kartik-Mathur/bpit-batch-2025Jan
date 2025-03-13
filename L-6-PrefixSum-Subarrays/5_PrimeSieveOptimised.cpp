#include <iostream>
using namespace std;
bool a[10000005];

int main() {


	for (int i = 0; i < 10000005; ++i)
	{
		a[i] = true;
	}

	int n;
	cin >> n;

	for (int i = 2; i * i <= n; ++i)
	{
		if (a[i] == true) {
			for (int j = i * i; j <= n; j += i)
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
















