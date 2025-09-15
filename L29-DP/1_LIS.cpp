#include <iostream>
#include <vector>
using namespace std;
#define vvi(dp,n) vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
#define pb push_back

void printLIS(int *a, vector<int> &dp, int indx) {
	vector<int> lis;
	int len = dp[indx];
	lis.pb(a[indx]);
	len--;

	int j = indx - 1;
	while (len > 0) {
		if (dp[j] == len and a[j] < lis.back()) {
			lis.pb(a[j]);
			len--;
		}

		j--;
	}

	reverse(lis.begin(), lis.end());
	for (int i = 0; i < lis.size(); ++i)
	{
		cout << lis[i] << " ";
	}
	cout << endl;
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

	int ans = 0, indx;
	for (int i = 0; i < n; ++i)
	{
		if (dp[i] > ans) {
			ans = dp[i];
			indx = i;
		}
	}

	printLIS(a, dp, indx);
	return ans;
}

int main() {

	int a[] = {10, 9, 3, 5, 4, 11, 7, 8};
	int n = sizeof(a) / sizeof(int);
	vvi(dp, n + 2);

	cout << bottomUp(a, n) << endl;


	return 0;
}
















