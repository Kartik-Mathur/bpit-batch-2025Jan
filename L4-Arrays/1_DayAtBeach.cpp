#include <iostream>
using namespace std;

int main() {

	int a[100005];
	int n;

	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}

	int leftMax[100005], rightMin[100005];

	leftMax[0] = INT_MAX;
	int ans = a[0];
	for (int i = 1; i < n; ++i)
	{
		leftMax[i] = ans;
		ans = max(ans, a[i]);
	}

	ans = INT_MAX;
	for (int i = n - 1; i >= 0; --i)
	{
		ans = min(ans, a[i]);
		rightMin[i] = ans;
	}

	int res = 1;
	for (int i = 1; i < n; ++i)
	{
		if (leftMax[i] <= rightMin[i]) res++;
	}
	cout << res << endl;
	return 0;
}
















