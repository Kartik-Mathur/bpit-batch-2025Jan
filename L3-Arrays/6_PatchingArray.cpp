#include <iostream>
using namespace std;

int main() {

	int a[] = {1, 5, 10};
	int a_size = sizeof(a) / sizeof(int);
	int i = 0;
	int N = 20;
	int patchingCount = 0;

	int nextNumberNeeded = 1;
	int weCanGenerateTill = 0;
	`
	while (weCanGenerateTill < N) {
		// Jab tak hum nextNumberNeeded ko jaha tak generateKar skte usse upr nhi krte
		// there is no point
		if (weCanGenerateTill >= nextNumberNeeded) nextNumberNeeded = weCanGenerateTill + 1;
		else {
			// Patching hogi
			if (i < a_size and nextNumberNeeded >= a[i]) {
				weCanGenerateTill += a[i];
				i++;
			}
			else { // Patching nhi hogi
				patchingCount ++;
				weCanGenerateTill += nextNumberNeeded;
			}
		}
	}

	cout << patchingCount << endl;

	return 0;
}
















