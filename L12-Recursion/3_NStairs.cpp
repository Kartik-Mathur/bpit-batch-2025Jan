#include <iostream>
using namespace std;

int nstairs(int n, int k) {
	// base case
	if (n == 0) return 1;
	if (n < 0) return 0;
	// recursive case
	int ans = 0;
	for (int i = 1; i <= k; ++i)
	{
		ans += nstairs(n - i, k);
	}
	return ans;
}

int main() {

	int n = 4, k = 3;

	cout << nstairs(n, k) << endl;


	return 0;
}
















