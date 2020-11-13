
Time - O(H), where H = height of binary tree

TreeNode * searchBST(TreeNode* root, int val) {
	if (root == NULL)
		return root;
	if (root->val == val)
		return root;
	if (val < root->val)
		return searchBST(root->left, val);
	return searchBST(root->right, val);
}