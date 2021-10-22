/*
1319. Number of Operations to Make Network Connected
Medium

There are n computers numbered from 0 to n-1 connected by ethernet cables connections forming a network where connections[i] = [a, b] represents a connection between computers a and b. Any computer can reach any other computer directly or indirectly through the network.

Given an initial computer network connections. You can extract certain cables between two directly connected computers, and place them between any pair of disconnected computers to make them directly connected. Return the minimum number of times you need to do this in order to make all the computers connected. If it's not possible, return -1. 

 

Example 1:

Input: n = 4, connections = [[0,1],[0,2],[1,2]]
Output: 1
Explanation: Remove cable between computer 1 and 2 and place between computers 1 and 3.

Example 2:

Input: n = 6, connections = [[0,1],[0,2],[0,3],[1,2],[1,3]]
Output: 2

Example 3:

Input: n = 6, connections = [[0,1],[0,2],[0,3],[1,2]]
Output: -1
Explanation: There are not enough cables.

Example 4:

Input: n = 5, connections = [[0,1],[0,2],[3,4],[2,3]]
Output: 0

 

Constraints:

    1 <= n <= 10^5
    1 <= connections.length <= min(n*(n-1)/2, 10^5)
    connections[i].length == 2
    0 <= connections[i][0], connections[i][1] < n
    connections[i][0] != connections[i][1]
    There are no repeated connections.
    No two computers are connected by more than one cable.


*/

class Solution
{
public:
    void dfs(int src, vector<int> grp[], vector<int> &vis)
    {
        vis[src] = 1;
        for (auto i : grp[src])
        {
            if (!vis[i])
            {
                dfs(i, grp, vis);
            }
        }
        return;
    }

    int makeConnected(int n, vector<vector<int>> &connections)
    {
        int totalEdges = connections.size();

        if (totalEdges < n - 1)
            return -1;

        vector<int> grp[n], vis(n, 0);

        for (int i = 0; i < totalEdges; i++)
        {
            grp[connections[i][0]].push_back(connections[i][1]);
            grp[connections[i][1]].push_back(connections[i][0]);
        }

        int component = 0; // total connected graph

        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                component++;
                dfs(i, grp, vis);
            }
        }

        return component - 1;
    }
};