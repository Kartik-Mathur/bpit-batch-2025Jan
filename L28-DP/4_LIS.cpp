#include <iostream>
#include <vector>
using namespace std;
#define vvi(dp,n) vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
#define pb push_back
// T.C: O(2^N)
int lis(int *a, int i, int n, int pe = INT_MIN) {
	if (i == n) return 0;

	int op1 = 0, op2 = 0;
	// Take the ith element
	if (pe < a[i]) {
		op1 = 1 + lis(a, i + 1, n, a[i]);
	}
	// Ignore the ith element
	op2 = lis(a, i + 1, n, pe);

	return max(op1, op2);
}

// T.C: O(N^2), S.C: O(N^2)
int topDown(int *a, int i, int n, vector<vector<int> > &dp, int pindex = -1) {
	if (i == n) return dp[i][pindex + 1] = 0;

	if (dp[i][pindex + 1] != -1) return dp[i][pindex + 1];

	int op1 = 0, op2 = 0;
	// Take the ith element
	if (pindex == -1 || a[pindex] < a[i]) {
		op1 = 1 + topDown(a, i + 1, n, dp, i);
	}
	// Ignore the ith element
	op2 = topDown(a, i + 1, n, dp, pindex);

	return dp[i][pindex + 1] = max(op1, op2);
}

int bottomUp2(int *arr, int n) {
	// int n = arr.size();

	vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

	for (int i = n - 1; i >= 0; i--) {
		for (int prev = i - 1; prev >= -1; prev--) {
			int skip = dp[i + 1][prev + 1];

			int take = 0;
			if (prev == -1 || arr[i] > arr[prev]) {
				take = 1 + dp[i + 1][i + 1];
			}

			dp[i][prev + 1] = max(skip, take);
		}
	}

	return dp[0][0];
}

// T.C: O(N^2), S.C: O(N)
int bottomUp(int *a, int n) {
	vector<int> dp(n + 1, 1);

	for (int i = 0; i < n; ++i)
	{
		for (int j = i - 1; j >= 0; --j)
		{
			if (a[i] > a[j]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < n; ++i)
	{
		ans = max(ans, dp[i]);
	}
	return ans;
}

int lisOptimised(int *a, int n) {
	vector<int> lis;

	for (int i = 0; i < n; ++i)
	{
		if (lis.size() == 0) {
			lis.pb(a[i]);
		}
		else if (lis[lis.size() - 1] < a[i]) {
			lis.pb(a[i]);
		}
		else {
			// upper_bound returns the address of value greater than a[i]
			auto x = upper_bound(lis.begin(), lis.end(), a[i]);
			*x =  a[i];
		}
	}

	return lis.size();
}

int main() {

	int a[] = {10, 9, 3, 5, 4, 11, 7, 8};
	int n = sizeof(a) / sizeof(int);
	vvi(dp, n + 2);

	cout << lis(a, 0, n) << endl;
	cout << topDown(a, 0, n, dp) << endl;
	cout << bottomUp(a, n) << endl;
	cout << lisOptimised(a, n) << endl;

	// PRINTING THE LIS


	return 0;
}
















