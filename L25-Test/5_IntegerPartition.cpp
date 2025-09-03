#include <iostream>
#include <climits>
using namespace std;

int main() {

	int n; cin >> n;

	int dp[100000];

	dp[0] = 0;
	dp[1] = 0;
	dp[2] = 1;

	for (int i = 2; i <= n; ++i)
	{
		int ans = INT_MIN;
		for (int j = 1; j < i; ++j)
		{
			ans = max(ans, max(j * (i - j), j * dp[i - j]));
		}
		dp[i] = ans;
	}

	cout << dp[n] << endl;


	return 0;
}
















