#include <iostream>
using namespace std;

int lcs(string &a, int n, string &b, int m) {
	if (n == 0 || m == 0) {
		return 0;
	}

	if (a[n - 1] == b[m - 1]) {
		return 1 + lcs(a, n - 1, b, m - 1);
	}
	else {
		return max(
		           lcs(a, n - 1, b, m),
		           lcs(a, n, b, m - 1)
		       );
	}
}

int topDown(string &a, int n, string &b, int m, int dp[][100]) {
	if (n == 0 || m == 0) {
		return dp[n][m] = 0;
	}

	if (dp[n][m] != -1) return dp[n][m];

	if (a[n - 1] == b[m - 1]) {
		return dp[n][m] = 1 + topDown(a, n - 1, b, m - 1, dp);
	}
	else {
		return dp[n][m] = max(
		                      topDown(a, n - 1, b, m, dp),
		                      topDown(a, n, b, m - 1, dp)
		                  );
	}
}

void printLCS(string &a, string &b, int dp[][100]) {
	string ans = "";
	int n = a.size(), m = b.size();
	while (n > 0 and m > 0) {
		if (a[n - 1] == b[m - 1]) {
			ans.push_back(a[n - 1]);
			n--;
			m--;
		}
		else {
			if (dp[n - 1][m] == dp[n][m]) {
				n--;
			}
			else {
				m--;
			}
		}
	}

	reverse(ans.begin(), ans.end());
	cout << ans << endl;
}

int bottomUp(string &a, string &b) {
	int dp[100][100] = {0};
	for (int i = 0; i <= a.size(); ++i)
	{
		for (int j = 0; j <= b.size(); ++j)
		{
			if (i == 0 || j == 0) {
				dp[i][j] = 0;
			}
			else {
				if (a[i - 1] == b[j - 1]) {
					dp[i][j] = 1 + dp[i - 1][j - 1];
				}
				else {
					dp[i][j] = max(
					               dp[i - 1][j],
					               dp[i][j - 1]
					           );
				}
			}
		}
	}

	printLCS(a, b, dp);

	// for (int i = 0; i <= a.size(); ++i)
	// {
	// 	for (int j = 0; j <= b.size(); ++j)
	// 	{
	// 		cout << dp[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }

	return dp[a.size()][b.size()];
}

int main() {
	string a = "abcde";
	string b = "abce";
	int dp[100][100];
	memset(dp, -1, sizeof(dp));

	cout << lcs(a, a.size(), b, b.size()) << endl;
	cout << topDown(a, a.size(), b, b.size(), dp) << endl;
	cout << bottomUp(a, b) << endl;



	return 0;
}
















