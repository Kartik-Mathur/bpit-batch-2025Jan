#include <iostream>
#include <vector>
using namespace std;

int nstairs(int n, int k) { // O(K^N)
	if (n == 0) return 1;
	if (n < 0) return 0;

	int ans = 0;
	for (int i = 1; i <= k; ++i)
	{
		ans += nstairs(n - i, k);
	}

	return ans;
}

int topDown(int n, int k, vector<int> &dp) { //  O(N*K)
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

int bottomUp(int n, int k) { // O(n * k)
	vector<int> dp(n + 1, 0);

	dp[0] = 1;

	for (int i = 1; i <= n; ++i)
	{
		int ans = 0;
		for (int j = 1; i - j >= 0 and j <= k; ++j)
		{
			// if (i - j < 0) break;
			ans += dp[i - j];
		}

		dp[i] = ans;
	}

	return dp[n];
}

int optimisedStairs(int n, int k) { // O(N)
	vector<int> dp(n + 1, 0);

	dp[0] = 1;
	dp[1] = 1;

	for (int i = 2; i <= n; ++i)
	{
		dp[i] = 2 * dp[i - 1] - (i - 1 - k >= 0 ? dp[i - 1 - k] : 0);
	}

	return dp[n];
}


int main() {

	int n; cin >> n;
	int k = 3;
	vector<int> dp(n + 1, -1);

	cout << optimisedStairs(n, k) << endl;
	cout << topDown(n, k, dp) << endl;
	cout << bottomUp(n, k) << endl;
	cout << nstairs(n, k) << endl;


	return 0;
}
















