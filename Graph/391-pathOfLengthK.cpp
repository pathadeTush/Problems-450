#include <bits/stdc++.h>
using namespace std;

bool dfs(int src, int k, vector<vector<int>> adj[], vector<bool> &vis)
{
    vis[src] = true;
    if (k <= 0)
        return true;
    for (auto it : adj[src])
    {
        int v = it[0];
        int w = it[1];
        if (!vis[v])
        {
            bool found = dfs(v, k - w, adj, vis);
            if (found)
                return true;
        }
    }
    vis[src] = false;
    return false;
}

int main()
{
    int n, e;
    cin >> n >> e;
    vector<vector<int>> adj[n];

    for (int i = 0; i < e; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        vector<int> temp1, temp2;
        temp1.push_back(v);
        temp1.push_back(w);
        adj[u].push_back(temp1);
        temp2.push_back(u);
        temp2.push_back(w);
        adj[v].push_back(temp2);
    }
    int k, src;
    cin >> k >> src;

    vector<bool> vis(n, false);
    bool found = dfs(src, k, adj, vis);
    if (found)
        cout << "Yes\n";
    else
        cout << "No\n";

    return 0;
}