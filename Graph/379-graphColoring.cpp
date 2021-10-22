#include <bits/stdc++.h>
using namespace std;
/**
 * @brief Note: It will not always give minimum color. It is NP-complete problem and it can be solved by Backtracking. refer 392 problem
 * 
 */
vector<int> minColor(vector<int> adj[], int n)
{

    vector<int> color(n, -1);
    for (int i = 0; i < n; i++)
    {
        // mark isAvailable = false with index as a color value for color taken adjacent vertices
        vector<bool> isAvailable(n, true);
        for (auto j : adj[i])
        {
            if (color[j] != -1)
                isAvailable[color[j]] = false;
        }
        for (int j = 0; j < n; j++)
        {
            if (isAvailable[j])
            {
                color[i] = j;
                break;
            }
        }
    }

    return color;
}

int main()
{
    int N, E;
    cin >> N >> E;

    vector<int> adj[N];

    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> color = minColor(adj, N);

    int count = -1;
    for (int i = 0; i < N; i++)
    {
        cout << i << " --> " << color[i] << endl;
        count = max(count, color[i]);
    }

    cout << "color required:" << count + 1 << endl;

    return 0;
}