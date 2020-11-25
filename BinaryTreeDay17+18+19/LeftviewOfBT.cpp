

Time - O(N)
Space - O(N)

vector<Node*>v;

vector<Node*> leftView(Node* root)
{
	if (root == NULL)
		return;
	queue<Node*>q;
	q.push(root);
	q.push(NULL);
	int cnt = 0;

	while (!q.empty())
	{
		Node* f = q.front();
		q.pop();
		if (f == NULL)
		{
			cnt = 0;
			if (!q.empty())
				q.push(NULL);
		}
		else
		{
			cnt++;
			if (cnt == 1)
				v.push_back(f);
			if (f->left)
				q.push(f->left);
			if (f->right)
				q.push(f->right);
		}
	}
}