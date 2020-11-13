

Time - O(n)

void Preorder(Node* root)
{
	stack<Node*>st;
	st.push(root);

	while (!st.empty())
	{
		Node* f = st.top();
		st.pop();

		cout << f->data << " ";

		if (f->left)
			st.push(f->left);
		if (f->right)
			st.push(f->right);
	}
}