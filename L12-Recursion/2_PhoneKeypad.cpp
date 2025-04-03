#include <iostream>
using namespace std;

char keys[][10] = {
	"", "", "ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ"
};

void phoneKeypad(char *ip, int i, char*op, int j) {
	// base case
	if (ip[i] == '\0') {
		op[j] = '\0';
		cout << op << endl;
		return;
	}
	// recursive case
	int digit = ip[i] - '0';
	for (int k = 0; keys[digit][k] != '\0'; ++k)
	{
		op[j] = keys[digit][k];
		phoneKeypad(ip, i + 1, op, j + 1);
	}
}

int main() {
	char op[100];
	char ip[] = "23";

	phoneKeypad(ip, 0, op, 0);


	/*
		int digit = 7;
		cout << keys[digit] << endl;
		// keys[2] this is an array
		for (int k = 0 ; keys[digit][k] != '\0' ; k++) {
			cout << keys[digit][k] << "_";
		}
	*/
	return 0;
}
















