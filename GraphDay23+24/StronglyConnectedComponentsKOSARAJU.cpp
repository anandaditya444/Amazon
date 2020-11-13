
KOSARAJU ALGO

Time - O(V + E)


bool vis[N];

void dfs(vector<int>adj[], int src, stack<int>&st)
{
	vis[src] = 1;
	for (auto x : adj[src])
	{
		if (vis[x] == false)
			dfs(adj, x, st);
	}
	st.push(src);
}

vector<int>[] get_transpose(vector<int>adj[])
{
	vector<int>mat[N];
	for (int i = 0; i < V; i++)
	{
		for (auto x : adj[i])
			mat[x].push_back(i);
	}
	return mat;
}

void dfs2(vector<int>Transpose_adj[], int src)
{
	vis[src] = true;
	cout << src << " ";

	for (auto x : Transpose_adj)
	{
		if (vis[x] == false)
			dfs2(Transpose_adj, x);
	}
}


void SCC()
{
	stack<int>st;
	memset(vis, false, sizeof(vis));

	for (int i = 0; i < V; i++)
	{
		if (vis[i] == false)
			dfs(adj, i, stack);
	}

	Transpose the graph means reverse the direction of all the edges

	vector<int>Transpose_adj = get_transpose(adj);

	memset(vis, false, sizeof(vis));

	while (!st.empty())
	{
		int vertex = st.top();
		st.pop();
		if (vis[vertex] == false)
		{
			dfs2(Transpose_adj, vertex);
			cout << endl;
		}
	}
}