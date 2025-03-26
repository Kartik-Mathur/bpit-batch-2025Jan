#include <iostream>
using namespace std;
int a[100005];
int b[100005];
int ispresent[100005] = {0};

int main() {


	int n, m; cin >> n >> m;

	for (int i = 0; i < n; ++i)
	{
		int x; cin >> x;
		ispresent[x]++;
	}

	for (int i = 0; i < m; ++i)
	{
		int x; cin >> x;
		if (ispresent[x] > 0) {
			cout << x << " ";
			ispresent[x] --;
		}
	}


	return 0;
}

