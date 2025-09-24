#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;

int main() {
	/*
	INPUT:
		9
		Vishal 999999999
		Devansh 888888888
		Amrita 00000000
		Amrita 1111111111
		Devansh 3434343434
		Vishal 1211111111
		Devansh 8675645451
		Amrita 7775654353
		Vishal 666666666
	*/

	/*
	HASHMAP
	Vishal : 999999999,666666666,1211111111
	Devansh: 888888888,3434343434,8675645451
	.
	.
	.
	.
	..
	Amrita: 00000000,1111111111,7775654353
	*/

	unordered_map<string, list<int> > h;

	int n, number;
	string x;
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		cin >> x >> number;
		h[x].push_back(number);
	}
	cout << "Output: " << endl;
	for (auto p : h) {
		cout << p.first << " : ";
		for (auto no : p.second) {
			cout << no << " ";
		}
		cout << endl;
	}

	return 0;
}
















