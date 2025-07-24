#include <iostream>
#include <vector>
using namespace std;

int solve(int n) {
	if (n <= 1) return n;

	return solve(n - 1) + solve(n - 2);
}

int fibo(int n, vector<int> &dp) {
	if (n <= 1) return dp[n] = n;
	if (dp[n] != -1) return dp[n];

	return dp[n] = fibo(n - 1, dp) + fibo(n - 2, dp);
}

int bottomUp(int n) {
	vector<int> dp(n + 1);

	dp[0] = 0;
	dp[1] = 1;

	for (int i = 2; i <= n; ++i)
	{
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	return  dp[n];
}


int main() {

	int n;
	cin >> n;
	vector<int> dp(n + 1, -1);

	cout << fibo(n, dp) << endl;
	cout << bottomUp(n) << endl;
	cout << solve(n) << endl;

	return 0;
}
















