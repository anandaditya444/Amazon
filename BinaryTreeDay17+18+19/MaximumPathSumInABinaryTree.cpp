
Time - O(n)

int sum = INT_MIN;

int maxPathSum(Node* root, int sum)
{
	// Base case
	if (root == NULL)
		return 0;

	// l and r store maximum path sum going through left and
	// right child of root respectively
	int left = maxPathSum(root->left, sum);
	int right = maxPathSum(root->right, sum);

	// Max path for parent call of root. This path must
	// include at-most one child of root
	int mx_single = max(max(left, right) + root->data, root->data);

	// Max Top represents the sum when the Node under
	// consideration is the root of the maxsum path and no
	// ancestors of root are there in max sum path
	int mx_top = max(mx_single, left + right + root->data);

	sum = max(sum, mx_top);

	return mx_single;
}