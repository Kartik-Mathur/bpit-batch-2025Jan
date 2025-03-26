#include <iostream>
using namespace std;

int main() {

	int n;
	cin >> n;
	int ones = 0, zeros = 0, twos = 0;

	for (int i = 0; i < n; ++i)
	{
		int x; cin >> x;
		if (x == 0) zeros++;
		else if (x == 1) ones++;
		else twos++;
	}

	for (int i = 0; i < zeros; ++i)
	{
		cout << 0 << " ";
	}

	for (int i = 0; i < ones; ++i)
	{
		cout << 1 << " ";
	}

	for (int i = 0; i < twos; ++i)
	{
		cout << 2 << " ";
	}



	return 0;
}
















