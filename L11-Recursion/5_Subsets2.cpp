class Solution {
public:
	vector<vector<int> > ans;

	void solve(vector<int> &ip, int i, vector<int> &op) {
		// All the op[] are answer
		ans.push_back(op);

		// base case
		if (i == ip.size()) return;
		// recursive case
		for (int j = i; j < ip.size(); ++j)
		{
			if (j != i and ip[j] == ip[j - 1]) continue;

			op.push_back(ip[j]);
			solve(ip, j + 1, op);
			op.pop_back(); // backtracking
		}
	}

	vector<vector<int>> subsetsWithDup(vector<int>& ip) {
		vector<int> op;
		sort(ip.begin(), ip.end());
		solve(ip, 0, op);
		return ans;
	}
};










