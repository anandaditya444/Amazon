
Time - O(N)


/* Recursive function to print all the nodes at distance k in the
   tree (or subtree) rooted with given root. See  */
void printkdistanceNodeDown(node *root, int k)
{
	// Base Case
	if (root == NULL || k < 0)  return;

	// If we reach a k distant node, print it
	if (k == 0)
	{
		cout << root->data << endl;
		return;
	}

	// Recur for left and right subtrees
	printkdistanceNodeDown(root->left, k - 1);
	printkdistanceNodeDown(root->right, k - 1);
}