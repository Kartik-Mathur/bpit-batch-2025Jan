#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n = 3, m = 3;
	vector< vector<int> > v;

	// Initialisation of vectors
	vector<int> v1 = {1, 2, 3};
	vector<int> v2 = {11, 12, 13};
	vector<int> v3 = {21, 22, 23};

	v.push_back(v1);
	v.push_back(v2);
	v.push_back(v3);

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cout << v[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}
















