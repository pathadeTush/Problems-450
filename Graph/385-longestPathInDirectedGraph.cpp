#include <bits/stdc++.h>
using namespace std;

void dfs(int src, vector<int> adj[], vector<bool> &vis, vector<int> &path, vector<int> &longestPath)
{
    vis[src] = true;
    path[src] = 1;
    for (auto i : adj[src])
    {
        if (!vis[i])
        {
            dfs(i, adj, vis, path, longestPath);
        }
    }
    if (longestPath.size() < path.size())
    {
        longestPath = path;
    }
    path[src] = 0;
    return;
}

vector<int> longestPathLen(vector<int> adj[], int v)
{
    vector<bool> vis(v, false);
    vector<int> path, longestPath;

    for (int i = 0; i < v; i++)
    {
        if (!vis[i])
        {
            dfs(i, adj, vis, path, longestPath);
        }
    }
    return longestPath;
}

int main()
{
    int N, E;
    cin >> N >> E;
    vector<int> adj[N];

    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> longestPath;
    = longestPathLen(adj, N);

    return 0;
}