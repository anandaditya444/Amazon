
struct Node()
{
	int data;
	struct Node* left;
	struct Node* right;
};

struct Info
{
	bool isBST;
	int sz;
	int mx;
	int mn;
};

Info largestBST(Node* root)
{
	if (root == NULL)
	{
		return {true, 1, INT_MIN, INT_MAX};
	}
	if (root->left == NULL && root->right == NULL)
	{
		return {true, 1, root->data, root->data};
	}

	Info l = largestBST(root->left);
	Info r = largestBST(root->right);

	Info res;
	res.sz = l.sz + r.sz + 1;

	if (l.isBST && r.isBST && l.mx <= root->data && r.mn > root->data)
	{
		res.mn = min(l.mn, min(r.mn, root->data));
		res.mx = max(r.mx, max(l.mx, root->data));

		res.isBST = true;

	}
	else if (l.isBST || r.isBST)
	{
		res.sz = max(l.sz, r.sz);
		res.isBST = false;
	}
	return res;
}