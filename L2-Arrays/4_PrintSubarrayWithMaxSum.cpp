#include <iostream>
#include <climits>
using namespace std;

int main() {

	int a[] = {1, 2, -5, 3, 8, -2, 6};
	int n = sizeof(a) / sizeof(int);
	int sum;
	int ans = INT_MIN;
	int si, sj;

	for (int i = 0; i < n; ++i)
	{
		for (int j = i; j < n; ++j)
		{
			sum = 0;
			for (int k = i; k <= j; ++k)
			{
				sum += a[k];
			}

			if (sum > ans) {
				ans = sum;
				si = i; // Store the starting index of maxsum subarray
				sj = j; // Store the ending index of maxsum subarray
			}

		}
	}


	cout << "Sum : " << ans << endl;
	for (int i = si; i <= sj; ++i)
	{
		cout << a[i] << " ";
	}
	cout << endl;


	return 0;
}
















