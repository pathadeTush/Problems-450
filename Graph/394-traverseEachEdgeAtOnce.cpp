#include <bits/stdc++.h>
using namespace std;

inline bool solve(int src, vector<int> adj[], vector<vector<bool>> &vis, int e)
{
    if (e == 0)
        return true;
    for (auto it : adj[src])
    {
        if (!vis[src][it])
        {
            vis[src][it] = true;
            vis[it][src] = true;
            if (solve(it, adj, vis, e - 1))
                return true;
            vis[src][it] = false;
            vis[it][src] = false;
        }
    }
    return false;
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
        adj[u-1].push_back(v-1);
        adj[v-1].push_back(u-1);
    }

    bool possible = false;
    for (int i = 0; i < N; i++)
    {
        vector<vector<bool>> vis(N, vector<bool>(N, false));
        if (solve(i, adj, vis, E))
        {
           // cout <<"src: " << i + 1 << endl;
            possible = true;
            break;
        }
    }
    cout << (possible == true) ? 1 : 0;
    
    return 0;
}