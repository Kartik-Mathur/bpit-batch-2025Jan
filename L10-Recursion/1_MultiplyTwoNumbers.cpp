#include <iostream>
using namespace std;

int solve(int a, int b) {
	// base case
	if (b == 0) return 0;

	// recursive case
	return a + solve(a, b - 1);
}

int main() {

	cout << solve(5, 3) << endl;

	return 0;
}
















