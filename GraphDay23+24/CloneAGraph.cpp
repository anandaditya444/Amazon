

void cloneGraph(Node* src)
{
	map<int, vector<Node*> >m;
	queue<int>q;
	q.push(src->val);
	vis[src->val] = 1;
	Node* node = new Node;
	node->val = src->val;
	m[src->val] = node;

	while (!q.empty())
	{
		Node* f = q.front();
		q.pop();

		for (auto x : adj[f])
		{
			if (!vis[x])
			{
				vis[x] = 1;
				q.push(x);
				Node* node = new Node;
				node->val = x;
				m[x].push_back(node);
			}
		}
	}
}

void bfs(Node* src)
{
	vector<Node*>v;
	if (src == NULL)
		return v;
	queue<Node*>q;
	q.push(src);
	vis[src] = 1;
	v.push_back(src);

	while (!q.empty())
	{
		Node* f = q.front();
		q.pop();
		v.push_back(f);

		for (auto x : adj[f])
		{
			if (!vis[x])
			{
				q.push(x);
				vis[x->val] = 1;
			}
		}
	}
}