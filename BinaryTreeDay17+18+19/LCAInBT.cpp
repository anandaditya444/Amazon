
Time - O(N)

void LCA(Node* root, Node* p, Node* q)
{
	if (root == NULL || root == p || root == q)
		return root;
	if (p == NULL || q == NULL)
		return NULL;
	Node* left = LCA(root->left, p, q);
	Node* right = LCA(root->right, p, q);

	return !left ? right : !right ? left : root;
}

1
2     3
4   5  6  7

LCA of {5, 6}

p = 5
    q = 6






        1