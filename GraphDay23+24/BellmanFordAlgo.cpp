
Time - O(V*E)

Bellman ford algo is used to find minimum distance between a source node to all the vertices in a directed graph


struct Edge {
	int src, dest, weight;
};

struct Graph {
	int V, E;
	Edge* edges;
}

void BellmanFord(Graph* graph, int src)
{
	int vertices = graph->V;
	int edges = graph->E;

	int dist[V];

	for (int i = 0; i < V; i++)
		dist[i] = INT_MAX;
	dist[src] = 0;

	Updating for the minimum distance

	for (int i = 1; i < V; i++)
		{
			for (int j = 0; j < E; j++)
			{
				int u = graph->edge[j].src;
				int v = graph->edge[j].dest;
				int wt = graph->edge[j].weight;

				if (dist[u] != INT_MAX && dist[v] > dist[u] + weight)
					dist[v] = dist[u] + weight;
			}
		}

	If we got minimum beyond the assigned one it it clear that graph has neagtive weight edges.


	for (int j = 0; j < E; j++)
	{
		int u = graph->edge[j].src;
		int v = graph->edge[j].dest;
		int wt = graph->edge[j].weight;

		if (dist[u] != INT_MAX && dist[v] > dist[u] + weight)
		{
			cout << "Negative weight cycles reported !" << endl;
			//dist[v] = dist[u] + weight;
		}
	}

}