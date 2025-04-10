#include <iostream>
#include <vector>
using namespace std;

bool isPalindrome(string s) {
	int i = 0, j = s.size() - 1;
	while (i < j) {
		if (s[i] != s[j]) return false;
		i++;
		j--;
	}
	return true;
}

void palindromePartition(string s, vector<string> &op) {
	// base case
	if (s.size() == 0) {
		for (int i = 0 ; i < op.size(); i++) cout << op[i] << ", ";
		cout << endl;
		return;
	}

	// recursive case
	for (int i = 1; i <= s.size(); i++) {
		string iskaKaamWeWillDo = s.substr(0, i);
		string iskaKaamRecWillDo = s.substr(i);

		if (isPalindrome(iskaKaamWeWillDo)) {
			op.push_back(iskaKaamWeWillDo);
			palindromePartition(iskaKaamRecWillDo, op);
			op.pop_back();
		}
	}
}

int main() {

	string s = "aaba";
	vector<string> op;
	palindromePartition(s, op);

	/*
		string s = "aaba";
		// s.substr(index, number_of_characters)
		for (int i = 1; i <= s.size(); ++i)
		{
			cout << "Is string ka kaam hum krenge: " << s.substr(0, i) << ", Recursion: " << s.substr(i) << endl;
		}
	*/
	return 0;
}
















