#include <iostream>
using namespace std;

int main() {

	char a[1000] = "Coding";
	int len = strlen(a); // Inbuilt function for length
	int k = 45;
	k %= len;

	// 1. Shift all characters k pos ahead
	for (int i = len - 1; i >= 0; --i)
	{
		a[i + k] = a[i];
	}

	cout << a << endl;

	// 2.Bring the last k characters to front
	for (int i = len, j = 0 ; j < k ; ++j, ++i)
	{
		a[j] = a[i];
	}

	cout << a << endl;

	// 3. Add NULL on len pos
	a[len] = '\0';
	cout << a << endl;


	return 0;
}
















