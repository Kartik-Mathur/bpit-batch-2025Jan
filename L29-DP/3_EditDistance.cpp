#include <iostream>
using namespace std;

int solve(string &a, int n, string &b, int m) {
	if (n == 0) return m;
	if (m == 0) return n;

	if (a[n - 1] == b[m - 1]) return solve(a, n - 1, b, m - 1);
	else {
		return 1 + min(solve(a, n - 1, b, m),
		               min(
		                   solve(a, n, b, m - 1),
		                   solve(a, n - 1, b, m - 1)
		               ));
	}
}

int topDown(string &a, int n, string &b, int m, int dp[][100]) {
	if (n == 0) return dp[n][m] = m;
	if (m == 0) return dp[n][m] = n;

	if (dp[n][m] != -1) return dp[n][m];

	if (a[n - 1] == b[m - 1]) return dp[n][m] = topDown(a, n - 1, b, m - 1, dp);
	else {
		return dp[n][m] = 1 + min(topDown(a, n - 1, b, m, dp),
		                          min(
		                              topDown(a, n, b, m - 1, dp),
		                              topDown(a, n - 1, b, m - 1, dp)
		                          ));
	}
}

int bottomUp(string &a, string &b) {
	int dp[100][100] = {};

	for (int i = 0; i <= a.size(); ++i)
	{
		for (int j = 0; j <= b.size(); ++j)
		{
			if (i == 0) dp[i][j] = j;

			else if (j == 0) dp[i][j] = i;
			else {
				if (a[i - 1] == b[j - 1]) {
					dp[i][j] = dp[i - 1][j - 1];
				}
				else {
					dp[i][j] = 1 + min(
					               dp[i - 1][j],
					               min(
					                   dp[i][j - 1],
					                   dp[i - 1][j - 1]
					               )
					           );
				}
			}
		}
	}

	return dp[a.size()][b.size()];
}

int main() {

	string a = "sunday";
	string b = "saturday";
	int dp[100][100];
	memset(dp, -1, sizeof(dp));
	cout << solve(a, a.size(), b, b.size()) << endl;
	cout << topDown(a, a.size(), b, b.size(), dp) << endl;
	cout << bottomUp(a, b) << endl;

	return 0;
}
















