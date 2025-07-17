#include <iostream>
#include <unordered_map>
#include <map>
using namespace std;

int main() {

	// unordered_map<string, int> h;
	map<string, int> h;

	// Insertion
	// pair<string, int> p("Mango", 100);
	pair<string, int> p;
	p.first = "Mango";
	p.second = 100;
	h.insert(p);

	h.insert(make_pair("Apple", 120));

	h.insert({"Guava", 130});
	h.insert({"apple", 180});

	// Printing hashmaps
	// for (int i = 0; i < h.bucket_count(); ++i)
	// {
	// 	cout << i << " : ";

	// 	for (auto it = h.begin(i) ; it != h.end(i) ; it++) {
	// 		cout << "(" << it->first << ", " << it->second << ") ";
	// 	}

	// 	cout << endl;
	// }

	// Print
	// for (pair<string, int> p : h) {
	for (auto p : h) {
		cout << p.first << ", " << p.second << endl;
	}





	return 0;
}
















