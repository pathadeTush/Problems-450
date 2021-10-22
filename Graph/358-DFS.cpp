// vector<int> dfsOfGraph(int V, vector<int> adj[])
// {
//     vector<int> ans;
//     stack<int> s;
//     char *visited = (char *)calloc(sizeof(char), V);
//     s.push(0);
//     ans.push_back(0);
//     visited[0] = 1;

//     while (!s.empty())
//     {
//         int curr = s.top();
//         int found = 0;
//         for (auto i : adj[curr])
//         {
//             if (!visited[i])
//             {
//                 ans.push_back(i);
//                 s.push(i);
//                 visited[i] = 1;
//                 found = 1;
//                 break;
//             }
//         }

//         if (!found)
//             s.pop();
//     }
//     return ans;
// }

/*

DFS of Graph
Easy Accuracy: 49.62% Submissions: 79785 Points: 2

Given a connected undirected graph. Perform a Depth First Traversal of the graph.
Note: Use recursive approach to find the DFS traversal of the graph starting from the 0th vertex from left to right according to the graph..


Example 1:

Input:

Output: 0 1 2 4 3
Explanation: 
0 is connected to 1, 2, 4.
1 is connected to 0.
2 is connected to 0.
3 is connected to 0.
4 is connected to 0, 3.
so starting from 0, it will go to 1 then 2
then 4, and then from 4 to 3.
Thus dfs will be 0 1 2 4 3.

Example 2:

Input:

Output: 0 1 2 3
Explanation:
0 is connected to 1 , 3.
1 is connected to 2. 
2 is connected to 1.
3 is connected to 0. 
so starting from 0, it will go to 1 then 2
then back to 0 then 0 to 3
thus dfs will be 0 1 2 3. 


Your task:
You don’t need to read input or print anything. Your task is to complete the function dfsOfGraph() which takes the integer V denoting the number of vertices and adjacency list as input parameters and returns  a list containing the DFS traversal of the graph starting from the 0th vertex from left to right according to the graph.


Expected Time Complexity: O(V + E)
Expected Auxiliary Space: O(V)


Constraints:
1 ≤ V, E ≤ 104
*/
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    void dfs(int src, vector<int> adj[], vector<int> &visited, vector<int> &ans)
    {

        visited[src] = 1;
        ans.push_back(src);
        for (auto i : adj[src])
        {
            if (!visited[i])
            {
                dfs(i, adj, visited, ans);
            }
        }
        return;
    }
    //Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[])
    {
        vector<int> ans;
        vector<int> visited(V, 0);
        dfs(0, adj, visited, ans);
        return ans;
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
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
} // } Driver Code Ends