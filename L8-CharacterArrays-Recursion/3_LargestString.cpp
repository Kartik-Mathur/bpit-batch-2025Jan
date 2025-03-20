#include <iostream>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n, max_len = 0;
	char largest[100] = "";
	cin >> n;

	cin.get(); // Number ke baad wale character ko read krlo
	// ' ' or '\n' hoga and isse kahi store mat kro, therefore ignore
	// ho jaega apne aap
	char a[100];

	for (int i = 0; i < n; ++i)
	{
		cin.getline(a, 100);
		int len_a = strlen(a);
		if (len_a > max_len) {
			max_len = len_a;
			strcpy(largest, a);
		}

		// cout << "You entered " << i << " : " << a << endl;
	}

	cout << "Largest: " << largest << endl;

	return 0;
}
















