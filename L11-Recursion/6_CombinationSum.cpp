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
			op.push_back(ip[j]);
			solve(ip, target - ip[j], op, j);
			op.pop_back();
		}
	}

	vector<vector<int>> combinationSum(vector<int>& ip, int target) {
		vector<int> op;
		solve(ip, target, op);
		return ans;
	}
};