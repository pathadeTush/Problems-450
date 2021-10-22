#include <bits/stdc++.h>
using namespace std;

bool dfs(int src, vector<vector<int>> &adj, vector<bool> &vis, vector<int> &color, int clr)
{
    color[src] = clr;
    vis[src] = true;
    for (int i = 0; i < adj[0].size(); i++)
    {
        if (!vis[i] and adj[src][i] == 1)
        {
            if (!dfs(i, adj, vis, color, clr^1))
            {
                // printf("src: %d  color[src]: %d   i: %d  color[i]: %d   clr: %d \n", src, color[src], i, color[i], clr);
                return false;
            }
        }
        else if (i != src and adj[src][i] == 1 and color[i] == clr)
        {
            //printf("src: %d  color[src]: %d   i: %d  color[i]: %d   clr: %d \n", src, color[src], i, color[i], clr);
            return false;
        }
    }
    return true;
}

bool isBipartite(vector<vector<int>> &adj, int n)
{
    vector<int> color(n, -1);
    vector<bool> vis(n, false);

    return dfs(0, adj, vis, color, 0);
}

bool twoClique(vector<vector<int>> &adj, int n)
{
    // take complement of a graph
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            adj[i][j] = (i != j) ? !adj[i][j] : 0;

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //         cout << adj[i][j] << " ";
    //     cout << endl;
    // }

    return isBipartite(adj, n);
}
int main()
{
    int N;
    cin >> N;
    vector<vector<int>> adj(N, vector<int>(N));

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> adj[i][j];

    //cout << "Fine\n";

    cout << twoClique(adj, N) << endl;
    return 0;
}