#include <iostream>
#include <vector>
using namespace std;
#define vi vector<int>

int topDown(int amt, int *deno, int n, vi& dp) {
	if (amt == 0) return dp[amt] = 0;

	if (dp[amt] != -1) return dp[amt];

	int ans = INT_MAX;
	for (int i = 0; i < n; ++i)
	{
		if (amt >= deno[i]) {
			int x = topDown(amt - deno[i], deno, n, dp);
			ans = min(ans, (x == INT_MAX) ? INT_MAX : x + 1);
		}
	}

	return dp[amt] = ans;
}

int bottomUp(int amt, int *deno, int n) {
	vector<int> dp(amt + 1);

	dp[0] = 0; // Initialisation
	for (int i = 1; i <= amt; ++i)
	{
		int ans = INT_MAX;
		for (int k = 0; k < n; ++k)
		{
			if (i >= deno[k]) {
				int x = dp[i - deno[k]];
				ans = min(ans, (x == INT_MAX) ? INT_MAX : x + 1);
			}
		}

		dp[i] = ans;
	}

	return dp[amt];
}

int main() {
	int a[] = {1, 7, 10};
	int n = sizeof(a) / sizeof(int);
	int amt = 15;
	vi dp(amt + 1, -1);

	cout << topDown(amt, a, n, dp) << endl;
	cout << bottomUp(amt, a, n) << endl;

	return 0;
}









