#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Logic:
 * This problem can be solved using Dijkstras algo.(treat each edge weight as negative of original) But time is more O(Elog(V))
 * 
 * 
 * 1. Find topological order
 * 2. Then apply DFS for each node according to order and do the relaxation for each node 
 */

#define ninf -INT_MAX

void dfs(int src, vector<vector<int>> adj[], vector<bool> &vis, stack<int> &ans)
{
    vis[src] = true;
    for (auto it : adj[src])
    {
        if (!vis[it[0]])
            dfs(it[0], adj, vis, ans);
    }
    ans.push(src);
    return;
}

stack<int> topoSort(vector<vector<int>> adj[], int n)
{
    vector<bool> vis(n, false);
    stack<int> ans;
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            dfs(i, adj, vis, ans);
        }
    }
    //  reverse(ans.begin(), ans.end());
    return ans;
}

void longestPathDAG(int src, vector<vector<int>> adj[], int n)
{
    stack<int> order = topoSort(adj, n);

    vector<int> longDist(n, ninf);
    longDist[src] = 0;
    while (!order.empty())
    {
        int curr = order.top();
        order.pop();
        if(longDist[curr] == ninf)
            continue;
        for (auto it : adj[curr])
        {
            int v = it[0];
            int wt = it[1];
            longDist[v] = max(longDist[v], longDist[curr] + wt);
            order.push(v);
        }
    }
    for (auto i : longDist)
        if (i == ninf)
            cout << "INF ";
        else
            cout << i << " ";
    return;
}

// Using BFS  This algo is also working fine but it is not recommended to use here. Reason yet to know...
// void longestPathDAG(int src, vector<vector<int>> adj[], int n)
// {
//     vector<bool> vis(n, false);
//     vector<int> longDist(n, ninf);
//     longDist[src] = 0;

//     queue<int> que;
//     que.push(src);

//     while (!que.empty())
//     {
//         int curr = que.front();
//         que.pop();
//         // vis[curr] = true;
//         for (auto it : adj[curr])
//         {
//             int v = it[0];
//             int wt = it[1];
//             longDist[v] = max(longDist[v], longDist[curr] + wt);
//             que.push(v);
//         }
//     }
//     for (auto i : longDist)
//         if (i == ninf)
//             cout << "INF ";
//         else
//             cout << i << " ";
//     return;
// }

int main()
{
    int n, e;
    cin >> n >> e;
    vector<vector<int>> adj[n];

    for (int i = 0; i < e; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        vector<int> t;
        t.push_back(v);
        t.push_back(w);
        adj[u].push_back(t);
    }
    int src;
    cin >> src;
    longestPathDAG(src, adj, n);

    return 0;
}