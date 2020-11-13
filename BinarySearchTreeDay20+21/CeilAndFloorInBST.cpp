
Time - O(N)
Space - O(1)

int ceil = -1, floor = -1;

void ceilAndFloor(Node* root, int key)
{
	if (root == NULL)
		return;
	while (root)
	{
		if (root->val == key)
		{
			ceil = root->val;
			floor = root->val;
			return;
		}
		if (key < root->data)
		{
			ceil = root->data;
			root = root->left;
		}
		else
		{
			floor = root->data;
			root = root->right;
		}
	}
}