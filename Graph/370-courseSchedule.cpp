#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool dfs(int src, vector<int> adj[], vector<int> &vis, vector<int> &path, int v, int Time)
    {
        if (Time > v)
            return true;
        vis[src] = 1;
        path[src] = 1;
        for (auto i : adj[src])
        {
            if (!vis[i])
            {
                bool cycleFound = dfs(i, adj, vis, path, v, Time + 1);
                if (cycleFound)
                    return true;
            }
            else if (path[i])
                return true;
        }
        path[src] = 0;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        int v = numCourses; // no. of vertices
        vector<int> adj[v];

        for (auto i : prerequisites)
        {
            adj[i[0]].push_back(i[1]);
        }

        vector<int> vis(v, 0), path(v, 0);
        bool cycleFound = false;
        int Time = 1;
        for (int i = 0; i < v; i++)
        {
            if (!vis[i])
            {
                cycleFound = dfs(i, adj, vis, path, v, Time);
                if (cycleFound)
                    return false;
            }
        }
        return true;
    }
};