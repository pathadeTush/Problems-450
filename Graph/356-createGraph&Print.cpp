/*

Print adjacency list
Easy Accuracy: 45.12% Submissions: 22377 Points: 2

Given the adjacency list of a bidirectional graph. Your task is to return the adjacency list for each vertex.


Example 1:

Input:

Output: 
0-> 1-> 4 
1-> 0-> 2-> 3-> 4 
2-> 1-> 3 
3-> 1-> 2-> 4 
4-> 0-> 1-> 3
Explanation:
As 0,1 and 3 is connected to 4 so 4th row
of the list containing 4 and its connected
nodes 0,1 and 3 and we have to add those in
sorted order and same for every row.


Example 2:

Input:


Output: 
0-> 2-> 3 
1-> 2 
2-> 0-> 1 
3-> 0
Explanation:
As 2 and 3 is connected to 0 so 0th row
of the list containing 0 and its connected 
nodes 2 and 3 and we have to add those in
sorted order and same for every row. 


Your task:
You don’t need to read input or print anything. Your task is to complete the function printGraph() which takes the integer V denoting the number of vertices and adjacency list as input parameters and returns the list of list  contains the node itself with its connected nodes(as same as it is given in input adjacency  list).


Expected Time Complexity: O(V + E)
Expected Auxiliary Space: O(1)


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
    //Function to return the adjacency list for each vertex.
    vector<vector<int>> printGraph(int V, vector<int> adj[])
    {
        vector<vector<int>> ans;
        vector<int> temp;

        for (int i = 0; i < V; i++)
        {
            temp.clear();
            temp.push_back(i);
            for (auto j : adj[i])
                temp.push_back(j);

            ans.push_back(temp);
        }

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
        Solution obj;
        vector<vector<int>> ans = obj.printGraph(V, adj);
        for (int i = 0; i < ans.size(); i++)
        {
            for (int j = 0; j < ans[i].size() - 1; j++)
            {
                cout << ans[i][j] << "-> ";
            }
            cout << ans[i][ans[i].size() - 1];
            cout << endl;
        }
    }
    return 0;
} // } Driver Code Ends