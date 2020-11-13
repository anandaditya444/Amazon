

Time - O(N) or in worst case in which we have to traverse deep down to right subtree of every root->left Node,
     that case would cost us around O(Nlogn) time.

		     void flatten(Node* root)
	{
		if (root == NULL)
			return;
		while (root)
		{
			if (root->left && root->right)
			{
				Node* temp = root->left;
				while (temp->right)
					temp = temp->right;
				temp->right = root->right;
				root->right = root->left;
				root->left = NULL;
			}
			else if (root->left)
			{
				root->right = root->left;
				root->left = NULL;
			}
			root = root->right;
		}
	}