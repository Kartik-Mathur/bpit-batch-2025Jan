#include <iostream>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int a[100][100];
	int n, m;
	// n: no of rows, m: no of cols
	cin >> n >> m;
	int no = 1;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			a[i][j] = no++;
		}
	}

	for (int i = 0; i < n - 1; ++i)
	{
		for (int j = i + 1; j < m; ++j)
		{
			swap(a[i][j], a[j][i]);
		}
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}
















