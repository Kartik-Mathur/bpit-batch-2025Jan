#include <iostream>
using namespace std;

int main() {

	int i = 0;
	int n;
	cin >> n;

	while (i < n) {

		cout << i << " ";

		if (i == 3) {
			i++;
			continue;
		}

		i++;
	}

	return 0;
}
















