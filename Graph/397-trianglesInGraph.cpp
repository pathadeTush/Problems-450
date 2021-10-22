#include<bits/stdc++.h>
using namespace std;

/**
 * @brief For DIRECTED And UNDIRECTED Graph   (Provide two edges from i to j and j to i for undirected one as graph is being created a/c to directed graph)
 * 
 */

void solve(int src, vector<int>adj[], vector<bool>&vis, vector<bool>&path, vector<int>&parent, int &count){
    vis[src] = true;
    path[src] = true;

    for(auto it: adj[src]){
        if(!vis[it]){
            parent[it] = src;
            solve(it, adj, vis, path, parent, count);
        }
        else if(it != parent[src] and it == parent[parent[src]]){

            count++;
        }
    }
    path[src] = false;
    return;
}

int totalTriangles(vector<int>adj[], int n){
    vector<bool> vis(n, false), path(n, false);
    vector<int> parent(n, -1);
    int count = 0;

    for (int i = 0; i < n; i++){
        if(!vis[i]){
            solve(i, adj, vis, path, parent, count);
        }
    }
    return count;
}

int main(){
    int N, E;
    cin >> N >> E;
    vector<int> adj[N];

    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    cout << totalTriangles(adj, N) << endl;
    return 0;
}