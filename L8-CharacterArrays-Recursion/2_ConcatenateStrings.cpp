#include <iostream>
#include <cstring>
using namespace std;

void concatenate(char a[], char b[]) {
	int i = strlen(a);
	int j = 0;

	int len_b = strlen(b);

	while (j <= len_b) {
		a[i++] = b[j++];
	}
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	char a[100] = "Coding";
	char b[] = "Blocks";


	// concatenate(a, b); // User defined
	strcat(a, b); // Inbuilt
	cout << a << endl;


	return 0;
}
















