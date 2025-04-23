#include <iostream>
using namespace std;

void solve(int no, int inc) {
	if (no == 53) {
		cout << no << " ";
		return;
	}

	cout << no << " ";
	solve(no + inc, inc + 4);
	cout << no + inc << " ";
}

int main() {
	solve(3, 2);


	return 0;
}
















