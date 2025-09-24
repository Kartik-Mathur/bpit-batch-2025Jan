#include <iostream>
#include <unordered_map>
#include <map>
using namespace std;

int main() {

	unordered_map<string, int> h;

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		string x; int price;
		cin >> x >> price;
		h.insert({x, price});
	}

	for (auto p : h) {
		cout << p.first << " : " << p.second << endl;
	}

	return 0;
}
















