

Time - O(n)

void Inorder(Node* root)
{
	stack<Node*>s;
	Node* cur = root;
	//s.push(cur);

	while (cur != NULL && !st.empty())
	{
		while (cur != NULL)
		{
			st.push(cur);
			cur = cur->left;
		}


		Node* f = st.top();
		st.pop();
		cout << f->data << " ";

		cur = f->right;

	}