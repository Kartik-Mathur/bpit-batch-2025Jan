#include <iostream>
using namespace std;

void balancedParanthesis(char *a, int open, int close, int i, int n) {
	// base case
	if (i == 2 * n) {
		a[i] = '\0';
		cout << a << endl;
		return;
	}
	// recursive case
	if (open < n) {
		a[i] = '(';
		balancedParanthesis(a, open + 1, close, i + 1, n);
	}

	if (close < open) {
		a[i] = ')';
		balancedParanthesis(a, open, close + 1, i + 1, n);
	}
}

int main() {

	int n = 2;
	char a[100];
	balancedParanthesis(a, 0, 0, 0, n);

	return 0;
}
















