#include <iostream>
using namespace std;

int ways(int i, int j) {
	if (!i or !j) return 1;

	return ways(i - 1, j) + ways(i, j - 1);
}


int main() {

	cout << ways(3, 3) << endl;

	return 0;
}
















