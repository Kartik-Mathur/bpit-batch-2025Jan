class Solution {
public:
	string ans = "";
	void solve(string &s, int i, int j) {

		int x = 0;
		int len = s.size();
		while (i >= 0 and j < len and s[i] == s[j]) {
			i--;
			j++;
		}

		// i and j will point to a substring
		int palindromicStringLength = j - i - 1;

		if (ans.size() < palindromicStringLength) {
			ans = s.substr(i + 1, palindromicStringLength);
		}
	}

	string longestPalindrome(string s) {

		for (int i = 0; i < s.size(); ++i)
		{
			solve(s, i, i);
			solve(s, i, i + 1);
		}

		return ans;
	}
};