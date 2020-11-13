

Node* pre, *succ;

void findPreSucc(Node* root)
{
	if (root == NULL)
		return;
	if (root->val == key)
	{

		// the maximum value in left subtree is predecessor
		if (root->left)
		{
			Node* temp = root->left;
			while (temp->right)
				temp = temp->right;
			pre = temp;
		}


		// the minimum value in right subtree is successor
		if (root->right)
		{
			Node* temp = root->right;
			while (temp->left)
				temp = temp->left;
			succ = temp;
		}
		return;
	}
	if (key < root->val)
	{
		succ = root;
		findPreSucc(root->left, key);
	}
	else
	{
		pre = root;
		findPreSucc(root->right, key);
	}
}

