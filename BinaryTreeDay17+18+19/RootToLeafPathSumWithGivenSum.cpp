

/*
Given a tree and a sum, return true if there is a path from the root
down to a leaf, such that adding up all the values along the path
equals the given sum.

Strategy: subtract the node value from the sum when recurring down,
and check to see if the sum is 0 when you run out of tree.
*/
bool hasPathSum(node* Node, int sum)
{
	/* return true if we run out of tree and sum==0 */
	if (Node == NULL)
	{
		return (sum == 0);
	}

	else
	{
		bool ans = 0;

		int subSum = sum - Node->data;

		/* If we reach a leaf node and sum becomes 0 then return true*/
		if ( subSum == 0 && Node->left == NULL && Node->right == NULL )
			return 1;

		/* otherwise check both subtrees */
		if (Node->left)
			ans = ans || hasPathSum(Node->left, subSum);
		if (Node->right)
			ans = ans || hasPathSum(Node->right, subSum);

		return ans;
	}
}