#include <iostream>
using namespace std;

int fact(int n) {
	int ans = 1;
	for (int i = 1; i <= n; ++i)
	{
		ans *= i;
	}
	return ans;
}

int ncr(int n, int r) {
	int fact_n = fact(n);
	int fact_r = fact(r);
	int fact_nr = fact(n - r);

	return fact_n / (fact_r * fact_nr);
}

int main() {

	cout << ncr(5, 2) << endl;


	return 0;
}
















