
Time - O(n)

set<int>s;

bool findTarget(Node* root, int K)
{
	if (root == NULL)
		return false;
	if (s.count(K - root->val))
		return true;
	s.insert(root->val);
	return findTarget(root->left, K) || findTarget(root->right, K);
}