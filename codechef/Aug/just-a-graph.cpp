#include <bits/stdc++.h>
using namespace std;

void dfs(int src, vector<int>adj[], vector<bool> &vis){
    vis[src] = true;

    for(auto it: adj[src]){
        if(!vis[it]){
            dfs(it, adj, vis);
        }
    }
    return;
}

int main(){
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        vector<int> adj[n];

        vector<int> w(n, 0);
        for (int i = 0; i < n; i++)
            cin >> w[i];

       // sort(w.begin(), w.end());

        for (int i = 0; i < n; i++){
            for (int j = i + 1; j < n; j++){
                if(j - i != w[j] - w[i]){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        int ans = 0;
        vector<bool> vis(n, false);

        for (int i = 0; i < n; i++){
            if(!vis[i]){
                dfs(i, adj, vis);
                ans++;
            }
        }
        cout << ans << endl;
    }
}

/*

2
2
1 2
2
2 1


*/