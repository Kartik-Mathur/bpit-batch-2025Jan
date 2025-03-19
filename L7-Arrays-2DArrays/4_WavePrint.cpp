#include <iostream>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int a[][4] = {
		{1, 2, 3, 4},
		{5, 6, 7, 8},
		{9, 10, 11, 12},
		{13, 14, 15, 16},
	};
	int n = 4, m = 4;

	for (int j = 0; j < m; ++j)
	{
		if (j % 2 == 0) {
			for (int i = 0; i < n; ++i)
			{
				cout << a[i][j] << " ";
			}
		}
		else {
			for (int i = n - 1; i >= 0; --i)
			{
				cout << a[i][j] << " ";
			}
		}
	}

	cout << endl;
	return 0;
}
















