class Pair {
public:
	int choriKari, choriNahiKari;
};

class Solution {
public:
	Pair solve(TreeNode* root) {
		if (!root) return {0, 0};

		Pair left = solve(root->left);
		Pair right = solve(root->right);

		Pair p;
		p.choriKari = root->data + left.choriNahiKari + right.choriNahiKari;
		p.choriNahiKari = max(left.choriKari, left.choriNahiKari) +
		                  max(right.choriKari, right.choriNahiKari);
		return p;
	}

	int rob(TreeNode* root) {
		Pair ans = solve(root);
		return max(ans.choriNahiKari, ans.choriKari);
	}
};