#include <iostream>
#include <climits>
using namespace std;

int main() {

	int a[] = {1, 2, -5, 3, 8, -2, 6};
	int n = sizeof(a) / sizeof(int);
	int sum;
	int ans = INT_MIN;
	int si, sj;
	int ps[100] = {0};

	// Find the prefix sum first to find range sum
	ps[0] = a[0];
	for (int i = 1; i < n; ++i)
	{
		ps[i] = ps[i - 1] + a[i];
		// ps[i]: [0,i] range sum
		// ps[i-1]: [0,i-1] range sum
	}

	// Max Sum Algo

	for (int i = 0; i < n; ++i)
	{
		for (int j = i; j < n; ++j)
		{
			/*
			if (i - 1 >= 0) {
				sum = ps[j] - ps[i - 1];
			}
			else sum = ps[j];
			*/
			sum = ps[j] - ( i - 1 >= 0 ? ps[i - 1] : 0 );

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
















