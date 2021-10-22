// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    bool dfs(int src, vector<int> adj[], vector<int> &visited, vector<int> &path)
    {
        visited[src] = 1;
        path[src] = 1;

        for (auto i : adj[src])
        {
            if (!visited[i])
            {
                bool cycleFound = dfs(i, adj, visited, path);
                if (cycleFound)
                    return true;
            }
            else if (path[i])
                return true;
        }
        path[src] = 0;
        return false;
    }

    //Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[])
    {
        vector<int> visited(V, 0), path(V, 0);
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                bool cycleFound = dfs(i, adj, visited, path);
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
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}
// } Driver Code Ends


// //Function to detect cycle in a directed graph.
// bool isCyclic(int V, vector<int> adj[])
// {
//     // code here
//     vector<int> visited(V, 0);
//     vector<int> path(V, 0);

// //This for loop is for if the given graph is disconnected
//         for(int i = 0; i < V; i++)
// {
//     if (!visited[i])
//     {
//         bool cycleFound = dfs(i, adj, visited, path);
//         if (cycleFound)
//             return true;
//     }
// }
// return false;
// }

// bool isCyclic(int V, vector<int> adj[])
// {
//     vector<int> path(V, 0), visited(V, 0);
//     stack<int> s;

//     // This for loop is for if the given graph is disconnected
//     for (int j = 0; j < V; j++)
//     {
//         if (!visited[j])
//         {
//             s.push(j);
//             path[j] = 1;
//             visited[j] = 1;

//             while (!s.empty())
//             {
//                 int curr = s.top();
//                 int found = 0;
//                 for (auto i : adj[curr])
//                 {
//                     if (!visited[i])
//                     {
//                         path[i] = 1;
//                         s.push(i);
//                         visited[i] = 1;
//                         found = 1;
//                         break;
//                     }
//                     else if (path[i])
//                         return true;
//                 }

//                 if (!found)
//                 {
//                     path[curr] = 0;
//                     s.pop();
//                 }
//             }
//         }
//     }
//     return false;
// }