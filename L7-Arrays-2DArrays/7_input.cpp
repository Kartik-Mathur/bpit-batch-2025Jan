#include <iostream>
using namespace std;

void inputString(char a[], int n, char d = '\n') {
	char ch;
	int i = 0;
	ch = cin.get();

	while (ch != d and i < n - 1) {

		// cout << "You entered: " << ch << ", i: " << i++ << '\n';
		a[i++] = ch;

		ch = cin.get();
	}

	// cout << i << "\n";
	a[i] = '\0';
}

int main() {

	char a[100];

	inputString(a, 100, '.');
	cout << "Array: " << a << endl;

	/*
		char ch;
		// cin >> ch;
		ch = cin.get();

		if (ch == ' ' || ch == '\t' || ch == '\n') {
			cout << "You entered whitespace character\n";
		}
		else
			cout << ch << endl;
	*/
	return 0;
}
















