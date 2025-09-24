#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {

	ll t;
	cin >> t;

	while (t--) {
		ll n;
		cin >> n;

		vector<ll> expectedRank(n);
		string s;
		for (ll i = 0; i < n; ++i)
		{
			cin >> s >> expectedRank[i];
		}

		sort(expectedRank.begin(), expectedRank.end());

		ll currentRank = 1;
		ll ans = 0;
		for (ll i = 0; i < n; ++i)
		{
			ans += abs(currentRank - expectedRank[i]);
			currentRank++;
		}

		cout << ans << endl;
	}


	return 0;
}
















