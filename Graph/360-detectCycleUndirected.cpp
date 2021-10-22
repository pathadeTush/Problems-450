// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    bool dfs(int src, int par, vector<int> adj[], vector<int> &visited)
    {
        visited[src] = 1;
        for (auto i : adj[src])
        {
            if (!visited[i])
            {
                bool cycleFound = dfs(i, src, adj, visited);
                if (cycleFound)
                    return true;
            }
            else if (par != i)
                return true;
        }
        return false;
    }

    bool isCycle(int V, vector<int> adj[])
    {
        vector<int> visited(V, 0);
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                bool cycleFound = dfs(i, -1, adj, visited);
                if (cycleFound)
                    return true;
            }
        }
        return false;
    }
};

// { Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
} // } Driver Code Ends