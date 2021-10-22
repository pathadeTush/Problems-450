#include <bits/stdc++.h>
using namespace std;

vector<int> vertexCover(vector<int>adj[], int n, int e){
    vector<int> ans;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++)
    }
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

    vector<int> ans = vertexCover(adj, N, E);
    for(auto it: ans)
        cout << it << " ";
    return 0;
}