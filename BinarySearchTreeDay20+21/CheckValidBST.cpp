

#define ll long long
class Solution {
public:
	bool isValidBST(TreeNode* root, ll minn = -1e12, ll maxx = 1e12) {
		if (root == NULL)
			return true;
		if (root->val > minn && root->val < maxx && isValidBST(root->left, minn, (root->val)) && isValidBST(root->right, (root->val), maxx))
			return true;
		return false;
	}
};