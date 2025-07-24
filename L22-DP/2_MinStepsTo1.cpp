#include <iostream>
#include <vector>
using namespace std;

int solve(int n) {
	if (n == 1) return 0;

	int op1 = INT_MAX, op2 = INT_MAX, op3 = INT_MAX;

	op1 = solve(n - 1);
	if (n % 2 == 0)op2 = solve(n / 2);
	if (n % 3 == 0)op3 = solve(n / 3);

	return 1 + min(op1, min(op2, op3));
}

int topDown(int n, vector<int> &dp) {
	if (n == 1) return dp[n] = 0;

	if (dp[n] != -1) return dp[n];

	int op1 = INT_MAX, op2 = INT_MAX, op3 = INT_MAX;

	op1 = topDown(n - 1, dp);
	if (n % 2 == 0)op2 = topDown(n / 2, dp);
	if (n % 3 == 0)op3 = topDown(n / 3, dp);

	return dp[n] = 1 + min(op1, min(op2, op3));
}

int bottomUp(int n) {
	vector<int> dp(n + 1);

	dp[1] = 0;

	for (int i = 2; i <= n; ++i)
	{
		int op1 = INT_MAX, op2 = INT_MAX, op3 = INT_MAX;

		op1 = dp[i - 1];
		if (i % 2 == 0)op2 = dp[i / 2];
		if (i % 3 == 0)op3 = dp[i / 3];

		dp[i] = 1 + min(op1, min(op2, op3));
	}
	return dp[n];
}

int main() {

	int n;
	cin >> n;
	vector<int> dp(n + 1, -1);
	cout << topDown(n, dp) << endl;
	cout << bottomUp(n) << endl;
	cout << solve(n) << endl;



	return 0;
}
















