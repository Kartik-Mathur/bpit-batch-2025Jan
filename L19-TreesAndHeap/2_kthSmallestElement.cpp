#define node TreeNode
class Solution {
public:
	int cnt = 0;
	int ans;
	void solve(node* root, int k) {
		if (!root) return;

		solve(root->left, k);
		cnt++;
		if (cnt == k) {
			ans = root->val;
			return;
		}
		solve(root->right, k);
	}

	int kthSmallest(node* root, int k) {
		solve(root, k);
		return ans;
	}
};