#include <iostream>
#include <vector>
using namespace std;

int a[1000][1000];
int n, m;

int main() {
	int i, j;
	cin >> m >> n;

	for (int i = 0; i < m; ++i)
		for (int j = 0; j < n; ++j)
			cin >> a[i][j];

	for (int k = 0; k < n + m - 1; ++k)
	{
		if (k < n) {
			i = 0;
			j = k;
		}
		else {
			i = k - n + 1;
			j = n - 1;
		}


		vector<int> x;
		while (i<m and j >= 0) {
			x.push_back(a[i][j]);
			i++;
			j--;
		}


		if (k % 2 == 0) {
			for (int i = x.size() - 1; i >= 0; --i)
			{
				cout << x[i] << " ";
			}
		}
		else {
			for (int i = 0; i < x.size(); ++i)
			{
				cout << x[i] << " ";
			}
		}
	}

	return 0;
}
















