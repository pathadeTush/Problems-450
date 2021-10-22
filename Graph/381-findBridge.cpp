#include <bits/stdc++.h>
using namespace std;
/**
 * @brief Logic:
 * 1.Apply DFS and store the time of call for each vertex
 * 2.Now, bridges are those edges which are not connected to the any other nodes other that its parent.
 * So we have to identify if a particular edge is connected more than once or not
 * 3.To find these, while applying DFS when we encounter a node which is already visited then there 
 * might be possibility that current node might be connected to that node(ancestor other than parent) 
 * If it so then surely it can't be bridge.
 * 4.So in else part check it that edge is connected or not. This can be done by minimizing its inTime 
 * with visited node's inTime. 
 * 5.If inTime of current node gets minimized implies this node is connected to its ancestor(other than parent)
 * and hence it is not bridge.  
 * 6.Now for ancestor also we need to to do same minimization. Like if its descendent gets minimized then
 * this ancestor also should get minimized.
 * 7.If ancestor is not minimized it happens when its descnedent is not minimized (i.e, inTime[ancestor] < inTime[descendent]) then it is an bridge print it
 */

int Time = 0;

void dfs(int src, vector<int> adj[], vector<bool> &vis, vector<int> &inTime, vector<int> &parent)
{
    vis[src] = true;
    inTime[src] = Time++;
    for (auto i : adj[src])
    {
        if (!vis[i])
        {
            parent[i] = src;
            dfs(i, adj, vis, inTime, parent);
            inTime[src] = min(inTime[src], inTime[i]);

            if (inTime[i] > inTime[src])
                cout << src << " - " << i << endl;
        }
        else if (i != parent[src])
        {
            inTime[src] = min(inTime[src], inTime[i]);
        }
    }
    return;
}

void bridge(vector<int> adj[], int v)
{
    vector<int> inTime(v, -1), parent(v, -1);
    vector<bool> vis(v, false);

    for (int i = 0; i < v; i++)
    {
        if (!vis[i])
        {
            dfs(i, adj, vis, inTime, parent);
        }
    }
    return;
}

int main()
{
    int n, e;
    cin >> n >> e;

    vector<int> adj[n];
    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bridge(adj, n);

    return 0;
}