// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    bool dfs(int src, vector<int> adj[], vector<int> &vis, vector<int> &path, vector<int> &ans, int Time)
    {
        vis[src] = 1;
        path[src] = 1;
        ans[src] = max(ans[src], Time);
        for (auto i : adj[src])
        {
            if (!vis[i])
            {
                bool cycleFound = dfs(i, adj, vis, path, ans, Time + 1);
                if (cycleFound)
                    return true;
            }
            else if (path[i])
                return true;
            ans[i] = max(ans[i], Time + 1);
        }
        path[src] = 0;
        return false;
    }

    //Function to return list containing vertices in Topological order.
    vector<int> topoSort(int V, vector<int> adj[])
    {

        vector<int> vis(V, 0), ans(V, 0), path(V, 0);
        int Time = 1;
        bool cycleFound = false;
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                cycleFound = dfs(i, adj, vis, path, ans, Time);
                if (cycleFound)
                    break;
            }
        }
        if (cycleFound)
        {
            ans.clear();
            return ans;
        }
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int N, E;
        cin >> N >> E;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++)
        {
            cin >> u >> v;
            adj[u - 1].push_back(v - 1); // for 0 based indexing
        }

        // for (int i = 0; i < N; i++)
        // {
        //     cout << i + 1 << ": ";
        //     for (auto j : adj[i])
        //         cout << j+1 << " ";
        //     cout << endl;
        // }

        Solution obj;
        vector<int> res = obj.topoSort(N, adj);

        for (auto i : res)
            cout << i << " ";

        cout << endl;
    }

    return 0;
} // } Driver Code Ends