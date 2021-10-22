/*

Bipartite Graph
Medium Accuracy: 40.1% Submissions: 40036 Points: 4

Given an adjacency list of a graph adj  of V no. of vertices having 0 based index. Check whether the graph is bipartite or not.
 

Example 1:

Input: 

Output: 1
Explanation: The given graph can be colored 
in two colors so, it is a bipartite graph.

Example 2:

Input:

Output: 0
Explanation: The given graph cannot be colored 
in two colors such that color of adjacent 
vertices differs. 

 

Your Task:
You don't need to read or print anything. Your task is to complete the function isBipartite() which takes V denoting no. of vertices and adj denoting adjacency list of graph and returns a boolean value true if graph is bipartite otherwise returns false.
 

Expected Time Complexity: O(V)
Expected Space Complexity: O(V)

Constraints:
1 ≤ V, E ≤ 105
*/
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    bool dfs(int src, vector<int> adj[], vector<int> &color)
    {
        for (auto i : adj[src])
        {
            if (color[i] == -1)
            {
                color[i] = (color[src] == 0) ? 1 : 0;
                if (!dfs(i, adj, color))
                    return false;
            }
            else if (color[i] == color[src])
                return false;
        }
        return true;
    }

    bool isBipartite(int V, vector<int> adj[])
    {
        vector<int> color(V, -1);

        for (int i = 0; i < V; i++)
        {
            if (color[i] == -1)
            {
                color[i] = 0;
                if (!dfs(i, adj, color))
                    return false;
            }
        }
        return true;
    }

    //     // Logic: Bipartite graph can be color with at least 2 colors
    // 	bool isBipartite(int V, vector<int>adj[]){

    // 	    vector<int>color(V, -1);

    // 	    for(int i = 0; i < V; i++){
    // 	        vector<bool>isAvailable(V, true);

    // 	        for(auto j: adj[i]){
    // 	            if(color[j] != -1)
    // 	                isAvailable[j] = false;
    // 	        }

    // 	        for(int j = 0; j < V; j++){
    // 	            if(isAvailable[j]){
    // 	                if(j > 1) return false;
    // 	                color[i] = j;
    // 	                break;
    // 	            }
    // 	        }
    // 	    }
    // 	    return true;
    // 	}
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
        bool ans = obj.isBipartite(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
} // } Driver Code Ends