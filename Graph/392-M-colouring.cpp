// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

inline bool isSafe(int node, bool graph[101][101], vector<int> &color, int v, int m, int clr)
{
    for (int adjNode = 0; adjNode < v; adjNode++)
    {
        if (adjNode != node and graph[node][adjNode] and color[adjNode] == clr)
            return false;
    }
    return true;
}

bool solve(int node, bool graph[101][101], vector<int> &color, int v, int m)
{ 
    // if all node has been coloured
    if (node == v)
        return true;

    for (int clr = 0; clr < m; clr++){
        if(isSafe(node, graph, color, v, m, clr)){
            color[node] = clr;
            if(solve(node + 1, graph, color, v, m))
                return true;
            color[node] = -1;
        }
    }
    return false;
}

//Function to determine if graph can be coloured with at most M colours such
//that no two adjacent vertices of graph are coloured with same colour.
bool graphColoring(bool graph[101][101], int m, int v)
{
    // your code here
    vector<int> color(v, -1);

    if (solve(0, graph, color, v, m))
        return true;
    return false;
}

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++)
        {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++)
        {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }

        cout << graphColoring(graph, m, n) << endl;
    }
    return 0;
}
// } Driver Code Ends