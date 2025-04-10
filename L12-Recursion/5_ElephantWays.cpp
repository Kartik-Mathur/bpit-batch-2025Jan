#include <iostream>
using namespace std;

int ways(int i, int j) {
	if (!i and !j) return 1;

	int ans = 0;
	for (int k = 0; k < i; ++k)
	{
		ans += ways(k, j);
	}

	for (int k = 0; k < j; ++k)
	{
		ans += ways(i, k);
	}

	return ans;
}

int main() {

	cout << ways(5, 8) << endl;
	return 0;
}
















