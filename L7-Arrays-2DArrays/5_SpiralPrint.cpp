#include <iostream>
using namespace std;

void spiralPrint(int a[][100], int n, int m) {
	int sr = 0, sc = 0, er = n - 1, ec = m - 1;

	while (sr <= er and sc <= ec) {
		// 1. Print sr
		for (int c = sc; c <= ec; ++c)
		{
			cout << a[sr][c] << " ";
		}
		sr++;

		// 2. Print ec
		for (int r = sr; r <= er; ++r)
		{
			cout << a[r][ec] << " ";
		}
		ec--;

		// 3. Print er
		if (sr < er) {
			for (int c = ec; c >= sc; --c)
			{
				cout << a[er][c] << " ";
			}
			er--;
		}

		if (sc < ec) {
			// 4. Print sc
			for (int r = er; r >= sr; --r)
			{
				cout << a[r][sc] << " ";
			}
			sc++;
		}
	}
}


int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int a[100][100];
	int n, m;
	cin >> n >> m;
	int no = 1;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			a[i][j] = no++;
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

	spiralPrint(a, n, m);



	return 0;
}
















