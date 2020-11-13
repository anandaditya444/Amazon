
Time - O(n*logn) as we have used merge sort for linked list

Node* merge(Node* a, Node* b)
{
	if (a == NULL)
		return b;
	if (b == NULL)
		return a;
	Node* res;
	if (a->data <  b->data)
	{
		res = a;
		res->bottom = merge(a->bottom, b);
	}
	else
	{
		res = b;
		res->bottom = merge(a, b->bottom);
	}
	res->next = NULL;
	return res;
}


Node *flatten(Node *root)
{
	if (root == NULL)
		return root;
	return merge(root, flatten(root->next));
}