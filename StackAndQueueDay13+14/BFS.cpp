
const int N = 1e5 + 5;
vector<int>g[N];

void bfs(int src)
{
	queue<int>q;
	q.push(src);
	vis[src] = true;

	while (!q.empty())
	{
		int f = q.front();
		q.pop();

		for (auto x : g[f])
		{
			if (!vis[x])
			{
				q.push(x);
				vis[x] = true;
			}
		}
	}
}