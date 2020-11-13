

Time - O(V*V*V)

Approach - it is to find minimum distance between all the pairs in a directed graph

int dist[N][N];

for (int k = 0; k < V; k++)
{
	for (int i = 0; i < V; i++)
	{
		for (int j = 0; j < V; j++)
		{
			dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
		}
	}
}