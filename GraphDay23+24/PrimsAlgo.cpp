

Algorithm
1) Create a set mstSet that keeps track of vertices already included in MST.
2) Assign a key value to all vertices in the input graph. Initialize all key values as INFINITE.
Assign key value as 0 for the first vertex so that it is picked first.
3) While mstSet doesn’t include all vertices
….a) Pick a vertex u which is not there in mstSet and has minimum key value.
….b) Include u to mstSet.
….c) Update key value of all adjacent vertices of u. To update the key values, iterate through all adjacent
vertices. For every adjacent vertex v, if weight of edge u - v is less than the previous key value of v,
	update the key value as weight of u - v
	The idea of using key values is to pick the minimum weight edge from cut. The key values are used only for
		vertices which are not yet included in MST, the key value for these vertices indicate the minimum weight edges
			connecting them to the set of vertices included in MST.


			Time - (V*V) forr below implementation
			Time complexity can be reduced to O(E*LogV) if graph is represented as adjacency list



				int minKey(bool mstSet, int key)
			{
				int mn = INT_MAX, mn_idx;
				for (int v = 0; v < V; v++)
					{
						if (mstSet[v] == false && key[v] < mn)
						{
							mn = key[v];
							mn_idx = v;
						}
					}
					return mn_idx;
				}


void PrimMST(vector<int>adj[])
{
	bool mstSet[V];
	int key[V], parent[V];

	for (int i = 0; i < V; i++)
	{
		mstSet[i] = false;
		key[i] = INT_MAX;
	}

	parent[0] = -1;
	key[0] = 0;

	for (int i = 0; i < V; i++)
	{
		int u = minKey(mstSet, key);
		mstSet[u] = true;
		for (auto x : adj[u])
		{
			if (adj[x].size() && mstSet[x] == false && key[x] > adj[u][x])
			{
				key[x] = adj[u][x];
				parent[x] = u;
			}
		}
	}
}