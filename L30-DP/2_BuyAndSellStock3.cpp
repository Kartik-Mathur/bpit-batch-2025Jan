class Solution {
public:

	int solve(vector<int>& prices, int i, int totalTransactions, int dp[][5],
	          bool activeTransaction = false) {
		// base case
		if (i == prices.size() or totalTransactions == 4) {
			return dp[i][totalTransactions] = 0;
		}
		if (dp[i][totalTransactions] != -1) return dp[i][totalTransactions];
		// recursive case
		// 1. BUY KARNA ya ignore karna ek stock ko
		if (activeTransaction == false) {
			int op1 = -prices[i] + solve(prices, i + 1, totalTransactions + 1, dp, true);
			int op2 = 0 + solve(prices, i + 1, totalTransactions, dp, activeTransaction);
			return dp[i][totalTransactions] = max(op1, op2);
		}
		// 2. SELL KARNA ya ignore karna ek stock ko
		else {
			int op1 = +prices[i] + solve(prices, i + 1, totalTransactions + 1, dp, false);
			int op2 = 0 + solve(prices, i + 1, totalTransactions, dp, activeTransaction);
			return dp[i][totalTransactions] = max(op1, op2);
		}
	}

	int maxProfit(vector<int>& prices) {
		int dp[100001][5];
		memset(dp, -1, sizeof dp);
		return solve(prices, 0, 0, dp);
	}
};




















