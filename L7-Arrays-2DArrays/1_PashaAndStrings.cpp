#include <iostream>
using namespace std;
int cnt[100005] = {0};

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	string s;
	cin >> s;
	int len = s.size();
	int m;
	cin >> m;

	for (int i = 0; i < m; ++i)
	{
		int ai; cin >> ai;
		cnt[ai - 1]++;
	}

	for (int i = 1; i < len / 2 ; ++i)
	{
		cnt[i] += cnt[i - 1];
	}

	for (int i = 0; i < len / 2 ; ++i)
	{
		if (cnt[i] % 2) {
			swap(s[i], s[len - i - 1]);
		}
	}

	cout << s << endl;

	return 0;
}
















