#include <iostream>
using namespace std;

int knapsack(int *price, int *weight, int capacity, int n) {
	// base case
	if (n == 0 || capacity == 0) {
		return 0;
	}

	// recursive case
	int op1 = 0, op2 = 0;
	if (capacity >= weight[n - 1]) {
		op1 = price[n - 1] + knapsack(price, weight, capacity - weight[n - 1], n - 1);
	}
	op2 = 0 + knapsack(price, weight, capacity, n - 1);

	return max(op1, op2);
}


int topDown(int *price, int *weight, int capacity, int n, int dp[][100]) {
	// base case
	if (n == 0 || capacity == 0) {
		return dp[n][capacity] = 0;
	}
	if (dp[n][capacity] != -1) return dp[n][capacity];

	// recursive case
	int op1 = 0, op2 = 0;
	if (capacity >= weight[n - 1]) {
		op1 = price[n - 1] + topDown(price, weight, capacity - weight[n - 1], n - 1, dp);
	}
	op2 = 0 + topDown(price, weight, capacity, n - 1, dp);

	return dp[n][capacity] = max(op1, op2);
}

int bottomUp(int *price, int *weight, int N, int capacity) {
	int dp[100][100] = {0};

	for (int n = 1; n <= N; ++n)
	{
		for (int c = 1; c <= capacity; ++c)
		{
			int op1 = 0, op2 = 0;
			if (c >= weight[n - 1]) {
				op1 = price[n - 1] + dp[n - 1][c - weight[n - 1]];
			}
			op2 = dp[n - 1][c];
			dp[n][c] = max(op1, op2);
		}
	}

	return dp[N][capacity];
}

int main() {

	int price[] = {5, 3, 4, 7};
	int weight[] = {2, 1, 3, 4};
	int n = sizeof(price) / sizeof(int);
	int capacity = 5;
	int dp[100][100];
	memset(dp, -1, sizeof dp);
	cout << knapsack(price, weight, capacity, n) << endl;
	cout << topDown(price, weight, capacity, n, dp) << endl;
	cout << bottomUp(price, weight, n, capacity) << endl;



	return 0;
}
















