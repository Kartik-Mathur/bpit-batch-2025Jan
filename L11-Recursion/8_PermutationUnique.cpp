class Solution {
public:
	vector<vector<int> > x;
	void solve(vector<int>& a, int i = 0) {
		// base case
		if (i == a.size()) {

			x.push_back(a);
			return;
		}

		// recursive case
		int freq[25] = {0};
		for (int j = i; j < a.size(); j++) {
			// We have to prevent a digit to go at ith position once we have
			// already considered it..
			if (freq[a[j] + 10] != 0) continue;
			freq[a[j] + 10] = 1;
			swap(a[i], a[j]);
			solve(a, i + 1);
			swap(a[i], a[j]);
		}
	}

	vector<vector<int>> permuteUnique(vector<int>& nums) {
		// sort(nums.begin(), nums.end());
		solve(nums);
		return x;
	}
};













