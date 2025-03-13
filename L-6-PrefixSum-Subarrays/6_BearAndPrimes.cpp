#include <iostream>
#include <vector>
using namespace std;

int MAX_VAL = 1e7 + 5;
vector<bool> primes(MAX_VAL, true);
vector<int> freq(MAX_VAL, 0);
vector<int> ps(MAX_VAL, 0);

void sieve() {
	primes[0] = primes[1] = false;
	for (int i = 2; i * i < MAX_VAL; ++i)
	{
		if (primes[i] == true) {
			for (int j = i * i; j < MAX_VAL; j += i)
			{
				primes[j] = false;
			}
		}
	}
}

int main() {

	sieve();

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int x; cin >> x;
		freq[x]++;
	}

	// prime numbers se array ke kitne elements divide hote hai uska count
	for (int i = 2; i < MAX_VAL; ++i)
	{
		if (primes[i]) {
			for (int j = i; j < MAX_VAL; j += i)
			{
				ps[i] += freq[j];
			}
		}
	}

	// Actually mei find prefix sum
	for (int i = 2; i < MAX_VAL; ++i)
	{
		ps[i] = ps[i] + ps[i - 1];
	}

	int m;
	cin >> m;

	for (int i = 0; i < m; ++i)
	{
		int l, r;
		cin >> l >> r;

		l = min(l, MAX_VAL - 1);
		r = min(r, MAX_VAL - 1);

		cout << ps[r] - ps[l - 1] << endl;
	}

	return 0;
}
















