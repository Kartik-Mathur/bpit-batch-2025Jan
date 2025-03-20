#include <iostream>
using namespace std;

// int fact(int n) {
// 	// base case
// 	if (n == 0) return 1;

// 	// recursive case
// 	// fact(n) = n * fact(n-1)
// 	int chotiProblem = fact(n - 1); // Assume it
// 	int badiProblem = n * chotiProblem;

// 	return badiProblem;
// }

int fact(int n) {
	// base case
	if (n == 0) return 1;

	// recursive case
	return n * fact(n - 1);
}


int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	cout << fact(4) << endl;

	return 0;
}
















