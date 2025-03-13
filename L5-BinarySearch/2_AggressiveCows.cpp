#include <iostream>
#include<algorithm>
using namespace std;
int a[100005];
int n, totalCows;

bool kyaCowsPlaceHoPaai(int d) {
	int cowsPlaced = 1;
	int pc = a[0];
	for (int i = 1; i < n; ++i)
	{
		if (a[i] - pc >= d) {
			cowsPlaced++;
			pc = a[i];

			if (cowsPlaced == totalCows) return true;
		}
	}

	return false;
}

int aggressiveCows() {
	// 1. Find the search space
	int s = 0, e = a[n - 1] - a[0];
	int ans = 0;
	while (s <= e) {
		int mid = s + (e - s) / 2;
		if (kyaCowsPlaceHoPaai(mid)) {
			ans = mid;
			s = mid + 1;
		}
		else {
			e = mid - 1;
		}
	}

	return ans;
}

int main() {
	int t;
	cin >> t;

	while (t--) {

		cin >> n >> totalCows;

		for (int i = 0; i < n; ++i)
		{
			cin >> a[i];
		}

		sort(a, a + n);

		cout << aggressiveCows() << endl;
	}


	return 0;
}
















