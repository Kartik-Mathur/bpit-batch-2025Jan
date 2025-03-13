#include <iostream>
using namespace std;

int main() {

	int a[] = {1, 2, 3, 4, 5};
	int n = sizeof(a) / sizeof(int);

	int ps[100] = {0};
	// 1. Finding prefixsum array
	ps[0] = a[0];
	for (int i = 1; i < n; ++i)
	{
		ps[i] = ps[i - 1] + a[i];
	}

	// 2. Take mod of ps[] with n
	for (int i = 0; i < n; ++i)
	{
		ps[i] %= n;
	}

	// 3. Finding the remainders count
	int remaindersCount[100] = {1}; // this is to compensate for the
	// empty subarray jiska sum is zero toh usse remaindersCount mei pehle hi lelo

	// [1,0,0,0,0,0,0,0,0 .... 0]
	for (int i = 0; i < n; ++i)
	{
		remaindersCount[ps[i]]++;
	}

	// nc2 = n*(n-1)/2
	int ans = 0;
	for (int i = 0; i < n; ++i)
	{
		ans += (remaindersCount[i] * (remaindersCount[i] - 1) / 2);
	}

	cout << "Total subarrays: " << ans << endl;


	return 0;
}
















