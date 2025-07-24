#include <iostream>
#include <vector>
using namespace std;

int solve(int amount, vector<int> &deno) {
	if (amount == 0) return 0;

	int ans = INT_MAX;
	for (int i = 0; i < deno.size(); ++i)
	{
		if (amount >= deno[i]) {
			int cans = solve(amount - deno[i], deno);
			if (cans != INT_MAX) { // amount-deno[i] ke badle coins dena possible nhi h
				ans = min(cans + 1, ans);
			}
		}
	}

	return ans;
}

int topDown(int amount, vector<int> &deno, vector<int> &dp) {
	if (amount == 0) return dp[amount] = 0;

	if (dp[amount] != -1) return dp[amount];

	int ans = INT_MAX;
	for (int i = 0; i < deno.size(); ++i)
	{
		if (amount >= deno[i]) {
			int cans = topDown(amount - deno[i], deno, dp);
			if (cans != INT_MAX) { // amount-deno[i] ke badle coins dena possible nhi h
				ans = min(cans + 1, ans);
			}
		}
	}

	return dp[amount] = ans;
}

int bottomUp(int amount, vector<int> &deno) {
	vector<int> dp(amount + 1, INT_MAX);
	dp[0] = 0;

	for (int i = 1; i <= amount; ++i)
	{
		for (int j = 0; j < deno.size(); ++j)
		{
			if (i >= deno[j]) {
				int cans = dp[i - deno[j]];

				if (cans != INT_MAX) {
					dp[i] = min(dp[i], cans + 1);
				}
			}
		}
	}

	for (int i = 0; i <= amount; ++i)
	{
		cout << dp[i] << " ";
	}
	cout << endl;

	return dp[amount];
}


int main() {

	int amount;
	cin >> amount;

	vector<int> deno = {1, 7, 10};
	vector<int> dp(amount + 1, -1);

	cout << topDown(amount, deno, dp) << endl;
	cout << bottomUp(amount, deno) << endl;
	cout << solve(amount, deno) << endl;



	return 0;
}
















