class Solution {
public:

	int countPalindromes(string &s, int i, int j) {
		int x = 0;

		while (i >= 0 and j < len and s[i--] == s[j++]) x++;
		return x;
	}


	int countSubstrings(string s) {
		int ans = 0;

		for (int i = 0; i < s.size(); ++i)
		{
			// Assuming 1 character as the center
			// ith index
			ans += countPalindromes(s, i, i);

			// Assuming 2 charater at the center
			// ith and (i+1)th
			ans += countPalindromes(s, i, i + 1);
		}

		return ans;
	}
};