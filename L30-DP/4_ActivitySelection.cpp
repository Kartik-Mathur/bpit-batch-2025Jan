#include <bits/stdc++.h>
using namespace std;
int n;

class Activity {
public:
	int start, end;
};

Activity a[100000];

bool compare(Activity x, Activity y) {
	return x.end < y.end;
}

int main() {

	int t; cin >> t;
	while (t--) {
		cin >> n;

		for (int i = 0; i < n; ++i)
		{
			int start, end;
			cin >> start >> end;
			a[i] = {start, end};
		}

		sort(a, a + n, compare);

		int ans = 0;
		int prev_endTime = INT_MIN;
		for (int i = 0; i < n; ++i)
		{
			int new_startTime = a[i].start;
			if (new_startTime >= prev_endTime) {
				ans++;
				// Ab jo chal rahi hai uska end time lena hoga next activity ke liye...
				prev_endTime = a[i].end;
			}
		}

		cout << ans << endl;
	}

	return 0;
}
















