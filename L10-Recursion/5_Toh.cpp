#include <iostream>
using namespace std;

void toh(int n, char src, char helper, char des) {
	// base case
	if (n == 0) return;

	// recursive case
	toh(n - 1, src, des, helper);
	cout << n << " -> " << src << " to " << des << endl;
	toh(n - 1, helper, src, des);
}

int main() {

	int n = 3;
	toh(n, 'A', 'B', 'C');

	return 0;
}
















