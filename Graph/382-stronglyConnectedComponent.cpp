/*

Strongly Connected Components (Kosaraju's Algo)
Medium Accuracy: 49.73% Submissions: 27268 Points: 4

Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, Find the number of strongly connected components in the graph.
 

Example 1:

Input:

Output:
3
Explanation:

We can clearly see that there are 3 Strongly
Connected Components in the Graph

Example 2:

Input:

Output:
1
Explanation:
All of the nodes are connected to each other.
So, there's only one SCC.

 

Your Task:
You don't need to read input or print anything. Your task is to complete the function kosaraju() which takes the number of vertices V and adjacency list of the graph as inputs and returns an integer denoting the number of strongly connected components in the given graph.
 

Expected Time Complexity: O(V+E).
Expected Auxiliary Space: O(V).
 

Constraints:
1 ≤ V ≤ 5000
0 ≤ E ≤ (V*(V-1))
0 ≤ u, v ≤ N-1
Sum of E over all testcases will not exceed 25*106
*/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

/*
Steps:

Here, topological sort needed to find correct order in terms of finish time of DFS traversal for each vertex as a source. Becoz after taking transpose when we do DFS traversal there might be possibility that our DFS will not end exactly for whole connected component. It can traverse other component as well in 1 DFS call

1. Find topological order (to run our DFS full in depth)
2. Now take a transpose of a graph. In this way our we will desconnect 
   the connected component from other. 
   Becoz it won't gonna afect connected one as it's a connected
3. Now apply dfs a/c to topo sort order and store the count of how many dfs 
   has applied for element taken from topo order

*/

class Solution
{
public:
    void dfs(int src, vector<int> adj[], vector<bool> &vis, vector<int> &order)
    {
        vis[src] = true;
        for (auto i : adj[src])
        {
            if (!vis[i])
            {
                dfs(i, adj, vis, order);
            }
        }
        order.push_back(src);
        return;
    }

    vector<int> topoSort(vector<int> adj[], int v)
    {
        vector<bool> vis(v, false);
        vector<int> order;

        for (int i = 0; i < v; i++)
        {
            if (!vis[i])
            {
                dfs(i, adj, vis, order);
            }
        }
        reverse(order.begin(), order.end());
        return order;
    }

    //Function to find number of strongly connected components in the graph.
    int kosaraju(int v, vector<int> adj[])
    {
        // find topological order
        vector<int> order = topoSort(adj, v);

        // transpose the graph
        vector<int> transpose[v];
        for (int i = 0; i < v; i++)
        {
            for (auto j : adj[i])
            {
                transpose[j].push_back(i);
            }
        }

        // now apply dfs a/c to topo sort order
        int count = 0;
        vector<bool> vis(v, false);
        vector<int> temp; // just taken to satisfy dfs argument requirement

        for (int i = 0; i < v; i++)
        {
            if (!vis[order[i]])
            {
                dfs(order[i], transpose, vis, temp);
                count++;
            }
        }
        return count;
    }
};

// { Driver Code Starts.

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends