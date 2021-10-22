// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    bool dfs(int src, vector<int> adj[], vector<int> &vis, vector<int>&path, vector<int> &ans)
    {
        vis[src] = 1;
        path[src] = 1;
        for (auto i : adj[src])
        {
            if (!vis[i])
            {
                bool cycleFound = dfs(i, adj, vis, path, ans);
                if(cycleFound)
                    return true;
            }
            else if(path[i])
                return true;
        }
        path[src] = 0;
        ans.push_back(src);
        return false;
    }

    //Function to return list containing vertices in Topological order.
    vector<int> topoSort(int V, vector<int> adj[])
    {
        vector<int> vis(V, 0), ans, path(V, 0);
        bool cycleFound = false;
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                cycleFound = dfs(i, adj, vis, path, ans);
                if(cycleFound)
                    break;
            }
        }
        if(cycleFound)
        {
            ans.clear();
            return ans;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};

// { Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector<int> &res, vector<int> adj[])
{
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++)
    {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++)
    {
        for (int v : adj[i])
        {
            if (map[i] > map[v])
                return 0;
        }
    }
    return 1;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++)
        {
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }

    return 0;
} // } Driver Code Ends