class Solution {
public:
	vector<vector<int> > ans;

	void solve(vector<int>& ip, int target, vector<int> &op, int i = 0) {
		if (target < 0) return;
		// base case
		if (target == 0) {
			ans.push_back(op);
			return;
		}
		// recursive case
		for (int j = i ; j < ip.size(); j++) {
			if (j != i and ip[j] == ip[j - 1]) continue;

			op.push_back(ip[j]);
			solve(ip, target - ip[j], op, j + 1);
			op.pop_back();
		}
	}
	vector<vector<int>> combinationSum2(vector<int>& ip, int target) {
		sort(ip.begin(), ip.end());
		vector<int> op;
		solve(ip, target, op);
		return ans;
	}
};









