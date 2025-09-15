#include <iostream>
#include <vector>
using namespace std;
#define vvi(dp,n) vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

int solve(int i, int j, int cost[][4]) { // O(2^n)
	if (i == 0 and j == 0) return cost[0][0];
	if (i < 0 || j < 0) return INT_MAX;

	return cost[i][j] + min(solve(i - 1, j, cost), solve(i, j - 1, cost));
}

int topDown(int i, int j, int cost[][4], vector<vector<int> > &dp) { // O(n^2)
	if (i == 0 and j == 0) return dp[i][j] = cost[0][0];
	if (i < 0 || j < 0) return INT_MAX;

	if (dp[i][j] != -1) return dp[i][j];

	return dp[i][j] = cost[i][j] + min(topDown(i - 1, j, cost, dp), topDown(i, j - 1, cost, dp));
}

int bottomUp(int cost[][4], int n, int m) {
	vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

	for (int i = 0; i <= n; ++i)
	{
		for (int j = 0; j <= m; ++j)
		{
			if (!i and !j) dp[0][0] = cost[0][0];
			else {
				dp[i][j] = cost[i][j] + min((i - 1 >= 0 ? dp[i - 1][j] : INT_MAX),
				                            (j - 1 >= 0 ? dp[i][j - 1] : INT_MAX));
			}
		}
	}

	return dp[n][m];
}

int main() {

	int n, m;
	cout << "Enter n(max:3) and m(max:3): ";
	cin >> n >> m;
	int cost[][4] = {
		{1, 1, 2, 7},
		{4, 1, 1, 1},
		{5, 3, 8, 1},
		{10, 9, 6, 1}
	};
	vvi(dp, 100);
	cout << topDown(n, m, cost, dp) << endl;
	cout << bottomUp(cost, n, m) << endl;
	cout << solve(n, m, cost) << endl;

	return 0;
}
















