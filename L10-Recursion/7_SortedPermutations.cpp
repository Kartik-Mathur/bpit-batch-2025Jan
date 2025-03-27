#include <iostream>
using namespace std;

void permutations(string ip, string op) {
	// base case
	if (ip.size() == 0) {
		cout << op << " ";
		return;
	}
	// recursive case
	for (int i = 0; i < ip.size(); ++i)
	{
		char ch = ip[i];
		permutations(ip.substr(0, i) + ip.substr(i + 1)  , op + ip[i]);
	}
}

int main() {
	string s = "bac";
	sort(s.begin(), s.end());
	// int indx = 2;
	// cout << s.substr(0, indx) << endl;
	// cout << s.substr(indx + 1) << endl;


	permutations(s, "");

	return 0;
}
















