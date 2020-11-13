

Time - O(E*LogV)


void Dijkstra(list< pair<int, int> > adj)
{
	set<pair<int, int> >s;
	int dist[V];
	for (int i = 0; i < V; i++)
		dist[i] = INT_MAX;
	s.insert(make_pair{0, src});
	dist[src] = 0;

	while (!s.empty())
	{
		pair<int, int>ele = *s.begin();
		s.erase(ele);
		//int d = ele.first;
		int u = ele.second;

		for (auto v : adj[u])
		{
			int wt = *v.second;

			if (dist[v] > dist[u] + wt)
			{
				if (dist[v] != INT_MAX)
					s.erase(s.find(make_pair(dist[v], v)));
				dist[v] = dist[u] + wt;
				s.insert(make_pair(dist[v], v));
			}

		}
	}
}