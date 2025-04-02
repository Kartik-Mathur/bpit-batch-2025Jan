#include <iostream>
#include <vector>
using namespace std;

int main() {

	vector<int> v;
	// v.push_back(1);
	// v.push_back(2);
	// v.push_back(3);
	// v.push_back(4);
	// v.push_back(5);

	for (int i = 1; i <= 5; ++i)
	{
		v.push_back(i);
		cout << "After insertion " << i << ", size: " << v.size() << ", cap: " << v.capacity() << endl;
	}

	for (int i = 0; i < v.size(); ++i)
	{
		cout << v[i] << " ";
	}
	cout << endl;



	return 0;
}
















