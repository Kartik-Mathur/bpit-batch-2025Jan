#define node TreeNode
#define cameraNahiLaga 0
#define cameraLagaHai 1
#define underVigilance 2

class Solution {
public:
	int cameraCount = 0;
	int solve(node* root) {
		if (!root) return underVigilance;

		int leftSays = solve(root->left);
		int rightSays = solve(root->right);

		if (leftSays == cameraNahiLaga || rightSays == cameraNahiLaga) {
			cameraCount++;
			return cameraLagaHai;
		}
		else if (leftSays == cameraLagaHai || rightSays == cameraLagaHai) {
			return underVigilance;
		}
		else {
			// Both the children are underVigilance
			return cameraNahiLaga;
		}
	}

	int minCameraCover(node* root) {
		int rootState = solve(root);
		if (rootState == cameraNahiLaga) cameraCount++;
		return cameraCount;
	}
};







