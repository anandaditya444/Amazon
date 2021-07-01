


Time - O(n)

void Postorder(Node* root)
{
	stack<Node*>st1, st2;
	st1.push(root);

	while (!st1.empty())
	{
		Node* f = st1.top();
		st1.pop();
		st2.push(f);

		if (f->left)
			st1.push(f->left);
		if (f->right)
			st1.push(f->right);
	}

	while (!st2.empty())
	{
		cout << st2.top()->data << " ";
		st2.pop();
	}
}