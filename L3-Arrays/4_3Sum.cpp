#include <iostream>
using namespace std;

int main() {

	int a[] = { -1, 0, 1, 2, -1, -4};
	int n = sizeof(a) / sizeof(int);


	sort(a, a + n); // Sorting using inbuilt function

	for (int i = 0; i < n - 2; ++i)
	{
		if (a[i] > 0) break;

		// Ek baari jo fix ho gaya usse dobara nhi lena
		if (i > 0 and a[i] == a[i - 1]) continue;

		// Ek element ko fix kardo: a[i]
		int j = i + 1;
		int k = n - 1;
		while (j < k) {
			if (a[j] + a[k] == -a[i]) {
				cout << a[i] << ", " << a[j] << ", " << a[k] << endl;
				// Ek baari triplet mill gaya toh a[j] and a[k] dono ko hatado
				j++;
				k--;
				// Agar humne jo j ko lia hai already whi same j dobara aaya
				// toh ignore kardo un saare j's ko
				while (j < k and a[j] == a[j - 1]) j++;
			}
			else if (a[j] + a[k] < -a[i])j++;
			else k--;
		}
	}

	return 0;
}
















