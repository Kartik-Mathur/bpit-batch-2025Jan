#include <iostream>
#include <vector>
#include <stack>
using namespace std;
bool a[10000005];
int arr[1000005];
vector<int> primes;

void sieve() {
	for (int i = 0; i < 10000005; ++i)a[i] = true;

	for (int i = 2; i * i < 10000005; ++i)
	{
		if (a[i] == true) {
			for (int j = i * i; j < 10000005; j += i)
			{
				a[j] = false;
			}
			primes.push_back(i);
		}

	}
}

int main() {

	sieve();

	int n, queries;
	cin >> n;
	cin >> queries;
	stack<int> S, A, B;

	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
		S.push(arr[i]);
	}

	for (int i = 0; i < queries; ++i)
	{
		int currentPrime = primes[i];

		while (!S.empty()) {
			int e = S.top();
			if (e % currentPrime == 0) B.push(e);
			else A.push(e);

			S.pop();
		}

		while (!B.empty()) {
			cout << B.top() << endl;
			B.pop();
		}
		// Taaki agli query mei phr se agle prime number se divide krke
		// B mei daaloge else A mei
		S = A;
		while (!A.empty()) {
			A.pop();
		}
	}

	while (!S.empty()) {
		cout << S.top() << endl;
		S.pop();
	}



	return 0;
}
















