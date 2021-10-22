#include <bits/stdc++.h>
using namespace std;

#define inf INT_MAX
int minEdgeReverse(int src, int destn, vector<pair<int, int>> adj[], int n){
    // reverse all edges with weight 1

    for (int i = 0; i < n; i++)
    {
        for(auto it: adj[i]){
            adj[it.first].push_back({i, 1});
        }
    }

    // now find minDist from src to destn using dijkstras algo
    vector<bool> vis(n, false);
    vector<int> minDist(n, inf);
    minDist[src] = 0;

    priority_queue<pair<int, int>> pq; // (minDist, ele)
    pq.push({0, src});

    while(!pq.empty()){
        int curr = pq.top().second;
        pq.pop();
        if(vis[curr])
            continue;
        vis[curr] = true;

        for(auto it: adj[curr]){
            int v = it.first;
            int w = it.second;
            
            if(!vis[v]){
                if(minDist[v] > minDist[curr] + w)
                    minDist[v] = minDist[curr] + w;

                pq.push({-minDist[v], v});
            }
        }
    }

    return minDist[destn];
}

int main(){
    int N, E;
    cin >> N >> E;
    vector<pair<int, int>> adj[N];

    for (int i = 0; i < E; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back({v, 0});
    }

    int src, destn;
    cin >> src >> destn;

    cout << minEdgeReverse(src, destn, adj, N) << endl;

    return 0;
}
