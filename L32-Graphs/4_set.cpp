#include <iostream>
#include <set>
using namespace std;

int main() {
	// Data is sorted by default
	// Set will not accept duplicate data....
	set<pair<int, char> > s;
	// Pair ka data sort hoga as per first argument..
	s.insert({6, 'A'}); // O(logN)
	s.insert({4, 'B'}); // O(logN)
	s.insert({1, 'C'}); // O(logN)

	// To update inside set we need to delete and then insert again
	// set ke andar updation possible nhi hoti
	s.erase({1, 'C'}); // O(logN)
	s.insert({3, 'C'});



	for (auto sp : s) {
		cout << sp.first << ", " << sp.second << endl;
	}


	return 0;
}
















