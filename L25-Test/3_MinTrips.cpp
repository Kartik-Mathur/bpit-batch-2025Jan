#include <iostream>
#include <vector>
#include <climits>
using namespace std;
#define int long long
int n;
int totalTrips;

int totalTripsPossible(vector<int> &a, int t) {
	int currentTrips = 0;
	for (int i = 0; i < n; ++i)
	{
		currentTrips += t / a[i];
	}
	return currentTrips >= totalTrips;
}

int32_t main() {

	cin >> n;
	int min_time_taken_by_bus = INT_MAX;
	int max_time_taken_by_bus = INT_MIN;
	vector<int> a(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
		min_time_taken_by_bus = min(min_time_taken_by_bus, a[i]);
		max_time_taken_by_bus = max(max_time_taken_by_bus, a[i]);
	}

	cin >> totalTrips;

	int e = totalTrips * max_time_taken_by_bus;
	int s = min_time_taken_by_bus;

	int ans = INT_MAX;

	while (s <= e) {
		int m = s + (e - s) / 2;

		if (totalTripsPossible(a, m)) {
			ans = m;
			e = m - 1;
		}
		else {
			s = m + 1;
		}
	}


	cout << ans << endl;

	return 0;
}
















