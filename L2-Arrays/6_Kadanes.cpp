#include <iostream>
#include <climits>
using namespace std;

int main() {

	int a[] = { -1, -2, -5, 3, -8, -2, -6};
	int n = sizeof(a) / sizeof(int);
	int sum = 0;
	int ans = INT_MIN;


	bool isPositivePresent = false;
	for (int i = 0; i < n; ++i)
	{
		if (a[i] >= 0) {
			isPositivePresent = true;
		}

		ans = max(ans, a[i]); // -ve elements mei ans un sabka max hoga
	}


	if (isPositivePresent == true) {
		// Max Sum Algo
		for (int i = 0; i < n; ++i)
		{
			sum += a[i]; // Elements ko add karte jaao
			if (sum < 0) sum = 0; // Sum agar -ve ho toh make it 0

			ans = max(ans, sum); // ans ke andar max lete jaao
		}
	}

	cout << "Sum : " << ans << endl;



	return 0;
}
















