

Time - O(N) as we are traversing the tree only once
Space - O(N), that is due to recursive call stack

bool helper(Node* l, Node* r)
{
	if (!l && !r)
		return true;
	if (!l || !r)
		return false;
	if (l->val != r->val)
		return false;
	return helper(l->left, r->right) && helper(l->right, r->left);
}

bool isMirror(Node* root)
{
	if (root == NULL)
		return true;
	return helper(root->left, root->right);
}