/*

Negative weight cycle
Medium Accuracy: 55.15% Submissions: 9175 Points: 4

Given a weighted directed graph with n nodes and m edges. Nodes are labeled from 0 to n-1, the task is to check if it contains a negative weight cycle or not.
Note: edges[i] is defined as u, v and weight.
 

Example 1:

Input: n = 3, edges = {{0,1,-1},{1,2,-2},
{2,0,-3}}
Output: 1
Explanation: The graph contains negative weight
cycle as 0->1->2->0 with weight -1,-2,-3,-1.

Example 2:

Input: n = 3, edges = {{0,1,-1},{1,2,-2},
{2,0,3}}
Output: 0
Explanation: The graph does not contain any
negative weight cycle.

 

Your Task:
You don't need to read or print anyhting. Your task is to complete the function isNegativeWeightCycle() which takes n and edges as input paramater and returns 1 if graph contains negative weight cycle otherwise returns 0.
 

Expected Time Complexity: O(n*m)
Expected Space Compelxity: O(n)
 

Constraints:
1 <= n <= 100
1 <= m <= n*(n-1), where m is the total number of Edges in the directed graph.
*/
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Relax all edges n-1 times
    int isNegativeWeightCycle(int n, vector<vector<int>> edges)
    {
        bool isChange = false;

        vector<int> minDist(n, INT_MAX);
        minDist[0] = 0;

        int e = edges.size(), i = 0;
        while (i < n - 1)
        {
            isChange = false;
            for (int j = 0; j < e; j++)
            {
                int u = edges[j][0];
                int v = edges[j][1];
                int dist = edges[j][2];

                if (minDist[u] != INT_MAX and (minDist[u] + dist) < minDist[v])
                {
                    minDist[v] = minDist[u] + dist;
                    isChange = true;
                }
            }

            if (!isChange)
                break;
            i++;
        }

        if (i <= n - 1 and !isChange)
            return 0;

        isChange = false;
        for (int j = 0; j < e; j++)
        {
            int u = edges[j][0];
            int v = edges[j][1];
            int dist = edges[j][2];

            if (minDist[u] != INT_MAX and (minDist[u] + dist) < minDist[v])
            {
                minDist[v] = minDist[u] + dist;
                isChange = true;
            }
        }

        if (isChange)
            return 1;
        return 0;
    }
};

// { Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; i++)
        {
            int x, y, z;
            cin >> x >> y >> z;
            edges.push_back({x, y, z});
        }
        Solution obj;
        int ans = obj.isNegativeWeightCycle(n, edges);
        cout << ans << "\n";
    }
    return 0;
} // } Driver Code Ends