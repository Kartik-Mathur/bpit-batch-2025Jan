#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> v;
void permutations(char *a, int i) {
	// base case
	if (a[i] == '\0') {
		// cout << a << endl;
		string x(a);
		v.push_back(x);
		return;
	}
	// recursive case
	for (int j = i; a[j] != '\0'; ++j)
	{
		swap(a[i], a[j]);
		permutations(a, i + 1);
		swap(a[i], a[j]); // Backtracking
	}
}

int main() {

	char a[] = "abc";
	permutations(a, 0);
	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); ++i)
	{
		cout << v[i] << " ";
	}
	cout << endl;

	return 0;
}





