// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#define inf INT_MAX
class Solution
{
public:
    //Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<bool> mstSet(V, false);
        vector<int> parent(V, -1);
        vector<int> minDist(V, inf);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        parent[0] = -1;
        minDist[0] = 0;
        minHeap.push({0, 0});

        int sum = 0;
        while (!minHeap.empty())
        {
            int curr = minHeap.top().second;
            minHeap.pop();
            if (mstSet[curr])
                continue;
            mstSet[curr] = true;

            for (auto i : adj[curr])
            {
                int u = curr;
                int v = i[0];
                int wt = i[1];
                // dont do relaxation here only check for edge weight value
                if (mstSet[v] == false and minDist[v] > wt)
                {
                    sum += wt;
                    if (parent[v] != -1)
                        sum -= minDist[v]; // remove previously stored value for another edge of v
                    minDist[v] = wt;
                    parent[v] = u;
                    minHeap.push({minDist[v], v});
                }
            }
        }

        // sum = 0;

        // for (int i = 1; i < V; i++)
        // {
        //     int u = parent[i], v = i;
        //     for (auto j : adj[u])
        //     {
        //         if (j[0] == v)
        //         {
        //             sum += j[1];
        //             break;
        //         }
        //     }
        //     // cout << u << " - " << v << endl;
        // }

        return sum;
    }
};

// class Solution
// {
// 	public:

//     int spanningTree(int V, vector<vector<int>> adj[])
//     {

//         priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;

//         int source = 0;
//         pq.push({0,source});

//         int cost = 0;

//         vector<bool> visited(V,false);

//         pair<int,int> p;

//         while(!pq.empty()){

//             p = pq.top();
//             pq.pop();

//             if(visited[p.second] == true)
//             continue;

//             cost += p.first;

//             visited[p.second] = true;

//             int x = p.second;

//             for(int i = 0; i < adj[x].size(); i++){

//                 if(!visited[adj[x][i][0]]){

//                     pq.push({adj[x][i][1],adj[x][i][0]});
//                 }
//             }
//         }

//         return cost;

//     }
// };

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i = 0;
        while (i++ < E)
        {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1, t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }

        Solution obj;
        cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends