Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of vertices such that for every
    directed edge u v, vertex u comes before v in the ordering. Topological Sorting for a graph is not possible
        if the graph is not a DAG.

            For example, a topological sorting of the following graph is “5 4 2 3 1 0”. There can be more than one
            topological sorting for a graph. For example, another topological sorting of the following graph is “4 5 2 3 1 0”.
                The first vertex in topological sorting is always a vertex with in - degree as 0 (a vertex with no incoming edges).



https : //www.geeksforgeeks.org/topological-sorting/

                    /*This is a function problem.You only need to complete the function given below*/
// The Graph structure is as folows
                    /*  Function which sorts the graph vertices in topological form
                    *   N: number of vertices
                    *   adj[]: input graph
                    *   NOTE: You must return dynamically allocated array
                    */
                    map<int, int>vis;
list<int>v;

void dfshelper(vector<int>adj[], int src)
{
    vis[src] = 1;
    for (auto x : adj[src])
    {
        if (!vis[x])
            dfshelper(adj, x);
    }
    v.push_front(src);
}

int* topoSort(int V, vector<int> adj[])
{
    // dfshelper(adj,1);
    for (int i = 0; i < V; i++)
        vis[i] = 0;
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
            dfshelper(adj, i);
    }
    int n = v.size();
    cout << n << endl;
    int ans[n];
    for (int i = 0; i < n; i++)
        ans[i] = v[i];

    return ans;
}