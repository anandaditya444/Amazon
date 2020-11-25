

Time - O(E*LogV)

The code finds shortest distances from source to all vertices. If we are interested only in shortest distance
from the source to a single target, we can break the for the loop when the picked minimum distance vertex is
equal to target (Step 3.a of the algorithm).

	void Dijkstra(list< pair<int, int> > adj, int src)
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