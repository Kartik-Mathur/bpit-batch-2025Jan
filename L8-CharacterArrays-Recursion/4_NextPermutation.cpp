#include <iostream>
using namespace std;

// we are looking to find index a[i] < a[i+1]
int findIndex(char a[]) {
	int k = -1;
	int lena = strlen(a);
	for (int i = lena - 2; i >= 0; --i)
	{
		if (a[i] < a[i + 1]) {
			k = i;
			break;
		}
	}

	return k;
}

void reverseString(char a[], int i, int j) {
	while (i < j) {
		swap(a[i], a[j]);
		i++;
		j--;
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	char a[1000];
	cin >> a;

	int k = findIndex(a);

	if (k == -1) { // string poori max possible string h
		// String ko reverse krke print kardo
		// input could be: dcba
		// reverse karo-> abcd(this is answer)
		reverseString(a, 0, strlen(a) - 1);
		cout << a << endl;
	}
	else {
		int j = strlen(a) - 1;
		while (j > k) {
			if (a[j] > a[k]) {
				swap(a[j], a[k]);
				break;
			}

			j--;
		}

		reverseString(a, k + 1, strlen(a) - 1);
		cout << a << endl;
	}


	return 0;
}
















