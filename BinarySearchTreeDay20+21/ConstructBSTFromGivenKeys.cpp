

Time - O(N * LogN)

Node* constructBST(int start, int end)
{
	if (start > end)
		return NULL;
	int mid = (start + end) / 2;
	Node* root = new Node;
	root->val = mid;
	root->left = constructBST(start, mid - 1);
	root->right = constructBST(mid + 1, end);

	return root;
}

Node* constructBST(int start, int end)
{
	if (start > end)
		return NULL;
	int mid = (start + end) / 2;
	Node* root = new Node;
	root->val = mid;
	root->left = constructBST(start, mid - 1);
	root->right = constructBST(start, mid + 1);

	return root;
}