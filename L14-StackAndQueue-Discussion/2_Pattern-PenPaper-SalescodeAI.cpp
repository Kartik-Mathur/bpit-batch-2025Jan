#include <iostream>
using namespace std;

void solve(int no, int inc) {
	if (no == 12) {
		cout << no << " ";
		return;
	}

	cout << no << " ";
	solve(no + inc, inc);
	if ((no + inc) % 4 == 0)
		cout << no + inc << " ";
}

int main() {
	solve(2, 2);


	return 0;
}
















