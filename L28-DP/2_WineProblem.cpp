#include <iostream>
#include <vector>
using namespace std;
#define vvi(dp,n) vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

int solve(int *price, int i, int j, int day) {
	if (i > j) return 0;

	int op1 = price[i] * day + solve(price, i + 1, j, day + 1);
	int op2 = price[j] * day + solve(price, i, j - 1, day + 1);

	return max(op1, op2);
}

int topDown(int *price, int i, int j, int day, vector<vector<int>> &dp) {
	if (i > j) return dp[i][j] = 0;

	if (dp[i][j] != -1) return dp[i][j];

	int op1 = price[i] * day + topDown(price, i + 1, j, day + 1, dp);
	int op2 = price[j] * day + topDown(price, i, j - 1, day + 1, dp);

	return dp[i][j] = max(op1, op2);
}

int bottomUp(int *price, int n) {

	vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

	for (int i = n - 1; i >= 0; --i)
	{
		for (int j = i; j < n; ++j)
		{
			int day = n - (j - i);
			int op1 = price[i] * day + (i + 1 < n ? dp[i + 1][j] : 0);
			int op2 = price[j] * day + (j - 1 >= 0 ? dp[i][j - 1] : 0);

			dp[i][j] = max(op1, op2);
		}
	}

	return dp[0][n - 1];
}

int bottomUp2(int *price, int n) { // Diagonal Traversal
	vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

	for (int k = 0; k < n; ++k)
	{
		int i = 0; int j = k;

		while (i < n and j < n) {
			int day = n - (j - i);
			int op1 = price[i] * day + (i + 1 < n ? dp[i + 1][j] : 0);
			int op2 = price[j] * day + (j - 1 >= 0 ? dp[i][j - 1] : 0);

			dp[i][j] = max(op1, op2);
			i++; j++;
		}

	}

	return dp[0][n - 1];
}

int main() {

	int a[] = {2, 3, 5, 1, 4};
	int n = sizeof(a) / sizeof(int);
	vvi(dp, n);

	cout << topDown(a, 0, n - 1, 1, dp) << endl;
	cout << solve(a, 0, n - 1, 1) << endl;
	cout << bottomUp(a, n) << endl;
	cout << bottomUp2(a, n) << endl;


	return 0;
}
















