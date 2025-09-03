#include <iostream>
#include <vector>
using namespace std;
#define vi vector<int>

int solve(int n, int k) {
	if (n == 0) return 1;

	int ans = 0;
	for (int i = 1; i <= k; ++i)
	{
		if (n - i >= 0) {
			ans += solve(n - i, k);
		}
	}

	return ans;
}

int topDown(int n, int k, vi&dp) {
	if (n == 0) return dp[n] = 1;
	if (n < 0) return 0;

	if (dp[n] != -1) return dp[n];

	int ans = 0;
	for (int i = 1; i <= k; ++i)
	{
		ans += topDown(n - i, k, dp);
	}

	return dp[n] = ans;
}

int bottomUp(int n, int k) {
	vi dp(n + 1, 0);

	dp[0] = 1;
	for (int stair = 1; stair <= n; ++stair)
	{
		for (int i = 1; i <= k; ++i)
		{
			if (stair - i >= 0) dp[stair] += dp[stair - i];
		}
	}

	return dp[n];
}

int nstairs(int n, int k) {
	vi dp(n + 1, 0);

	dp[0] = dp[1] = 1;
	for (int stair = 2; stair <= n; ++stair)
	{
		dp[stair] = 2 * dp[stair - 1] - (stair - 1 - k >= 0 ? dp[stair - 1 - k] : 0);
	}

	return dp[n];
}

int main() {

	int n; cin >> n;
	int k = 3;
	vi dp(n + 1, -1);
	cout << topDown(n, k, dp) << endl;
	cout << bottomUp(n, k) << endl;
	cout << nstairs(n, k) << endl;

	cout << solve(n, k) << endl;

	return 0;
}
















