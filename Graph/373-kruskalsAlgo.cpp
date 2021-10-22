#include <bits/stdc++.h>
using namespace std;

//-------------------  Disjoint Set  ---------------------
// time complexity: O(4xalpha) ~ O(4)
void makeSet(int n, int rank[], int parent[])
{
    for (int i = 0; i < n; i++)
    {
        rank[i] = 0;
        parent[i] = i;
    }

    return;
}

void Union(int i, int j, int rank[], int parent[])
{
    if (rank[i] > rank[j])
        parent[j] = i;

    else if (rank[i] < rank[j])
        parent[i] = j;

    else
    {
        parent[j] = i;
        rank[i]++;
    }
    return;
}

int findParent(int i, int parent[])
{
    // if (parent[i] == i)
    //     return i;
    // // path compression
    // return (parent[i] = findParent(parent[i], parent));

    if (parent[i] != i)
    {
        parent[i] = findParent(parent[i], parent);
    }

    return parent[i];
}
// ---------------------------------------------------------------

typedef struct node
{
    int src;
    int destn;
    int weight;
} node;

inline node newnode(int u, int v, int wt)
{
    node nn;
    nn.src = u;
    nn.destn = v;
    nn.weight = wt;
    return nn;
}

bool compare(node a, node b)
{
    return (a.weight < b.weight);
}

void kruskalsAlgo(vector<vector<int>> adj[], int n, node edges[], int e)
{
    sort(edges, edges + e, compare);

    int parent[n], rank[n];
    makeSet(n, rank, parent);
    int i = 0, j = 0;
    while (i < n - 1)
    {
        int u = edges[j].src;
        int v = edges[j].destn;
        int wt = edges[j].weight;

        int u_par = findParent(u, parent);
        int v_par = findParent(v, parent);

        if (u_par != v_par)
        {
            Union(u_par, v_par, rank, parent);
            i++;

            cout << u << " - " << v << "\t" << wt << endl;
        }
        j++;
    }
    return;
}

int main()
{
    int n, e;
    cin >> n >> e;
    vector<vector<int>> adj[n];
    node edges[e];
    for (int i = 0; i < e; i++)
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
        edges[i] = newnode(u, v, w);
    }

    kruskalsAlgo(adj, n, edges, e);

    return 0;
}