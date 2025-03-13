#include <iostream>
using namespace std;

int prime[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};

int main() {

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;
		int a[1005];
		// by default sabhi par color 0 kar diya
		int rang[1005] = {0};

		for (int i = 0; i < n; ++i) cin >> a[i];

		int color = 1; // color hum 1 se fill krna start krenge

		for (int i = 0; i < 11; ++i)
		{
			int x = prime[i];
			// Jo bhi element colored nhi hai aur multiple hai x ka
			// un sab par same color kardo
			bool kyaColorFillKia = false;
			for (int j = 0; j < n; ++j)
			{
				if (rang[j] != 0) continue; // ek baari jispar color kar diya
				// uspar dobara color nhi krna hai

				if (a[j] % x == 0) { // saare elements jo x se divide hote h
					// unpar same color kar skte hai
					rang[j] = color;
					kyaColorFillKia = true;
				}
			}

			// Agar loop ke andar currentColor use hua toh aage walo par next
			// color use krenge otherwise abhi wala use hi nhi kia toh whi karo
			if (kyaColorFillKia) color++;

		}

		cout << color - 1 << endl;
		for (int i = 0; i < n; ++i)
		{
			cout << rang[i] << " ";
		}
		cout << endl;

	}

	return 0;
}
















