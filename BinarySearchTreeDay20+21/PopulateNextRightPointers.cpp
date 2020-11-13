

Node* populate(Node* root)
{
	if (root == NULL)
		return NULL;
	if (root->left)
	{
		root->left->next = root->right;
		if (root->next)
		{
			root->right->next = root->next->left;
		}
	}
	populate(root->left);
	populate(root->right);

	return root;
}