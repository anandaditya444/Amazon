https://www.geeksforgeeks.org/detect-cycle-direct-graph-using-colors/

Time complexity: O(V + E), where V is the number of vertices and E is the number of edges in the graph.
Space Complexity : O(V).
Since an extra color array is needed of size V.

int n, m;
int grid[100][100];
int vis[100];

bool isCyclePresent(int src)
{
  if (vis[src] == 1)
    return true;
  if (vis[src] == 2)
    return false;
  vis[src] = 1;
  for (auto x : adj[src])
  {
    if (isCyclePresent(x))
      return true;
  }
  vis[src] = 2;
  return false;
}


// bool findLoop(int v)
// {
//   if(vis[v]==1)
//     return 1;
//   if(vis[v]==2)
//     return 0;
//   vis[v]=1;
//   for(auto &it:g[v])
//   {
//     if(findLoop(it))
//       return 1;
//   }
//   vis[v]=2;
//   return 0;
// }


bool iscycle()
{
  for (int i = 0; i < n; i++)
  {
    if (!vis[i])
    {
      if (findloop(i))
      {
        return true;
      }
    }
  }
  return false;
}

int main()
{
  cin >> n >> m;
// for(int i=0;i<n;i++)
// {
//  for(int j=0;j<m;j++)
//  {
//    cin>>grid[i][j];
//  }
// }

  for (int i = 0; i < m; i++)
  {
    int x, y;
    cin >> x >> y;
    grid[x][y] = 1;
//grid[y][x] = 1;
  }

  if (iscycle())
    cout << "Cycle" << endl;
  else
    cout << "No cycle" << endl;


  return 0;
}
