/*
The question demands the concept of using disjoint sets. (find and union with rank and path compression).

However, this method below using DFS also works (which I think i pretty similar to the editorial) :

We need to find the distinct sets (i.e. if x and y are from same country, they belong to same set) to get the answer. Let's say set A has a elements,set B has b elements.

Answer = a x b. [Because actual formula is to select one from set A and another one from set B = aC1 x bC1 = a x b]

Similarly, let's calculate answer for 4 sets - A,B,C,D with a,b,c,d elements respectively.

Lets say somehow I find set A has a elements.

Answer = 0 (Since I don't have another country to pair with)

Now, I find set B with b elements.

Answer = axb; .................................................(1)

Then, I find set C with c elements.

Answer = (axb) + (axc) + (bxc) [because we can select a pair from A and B, or A and C or B and C]

But this can be written as

Answer = (axb) + (a+b)xc ......................................(2)

Now I find set D with d elements, and I've examined all people.

Answer = (axb) + (axc) + (axd) + (bxc) + (bxd) + (cxd)

Or

Answer = (axb) x (a+b)xc + (a+b+c)xd ..........................(3)

Do you see the pattern? That means when we find a new set, the new answer is the old answer + the sum of old values x new value.

Now, how do we find the people of same country?

Make each person a node. Draw an edge for every input (i.e. they belong to same country)

Now, run DFS starting from every node (if the node is not already visited). DFS should return the nodes in that set.

Example:

10 7
0 2
1 8
1 4
2 8
2 6
3 5
6 9

Graph:

0 ---- 2 ---- 6     3     7
          |        |      |
          |        |      |
1 ---- 8       9     5
|
|
4

3 sets {0,1,2,4,6,8,9} {3,5} {7}

DFS from 0 returns "7"

answer = 0

DFS from 1 should not start [since we have vistied 1 while dfs(0)]

DFS from 2 should not start ...

DFS from 3 returns "2"

answer = 7 * 2 = 14

DFS from 7 returns "1"

answer = 14 + (7+2)*1

answer = 23
*/

long long journeyToMoon(int n, vector<vector<int>> astronaut)
{
    vector<int> adj[n];

    for (auto it : astronaut)
    {
        int u = it[0];
        int v = it[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> connectedNode;
    vector<bool> vis(n, false);

    for (int i = 0; i < n; i++)
    {
        int totalNode = 0;
        if (!vis[i])
        {
            dfs(i, adj, vis, totalNode);
            connectedNode.push_back(totalNode);
        }
    }
    int sz = connectedNode.size();
    if (sz == 1)
        return 0;

    vector<int> cumSum(sz, 0);
    cumSum[0] = connectedNode[0];
    for (int i = 1; i < sz; i++)
        cumSum[i] = connectedNode[i] + cumSum[i - 1];

    long long ans = 0;
    for (int i = 0; i < sz; i++)
        ans += connectedNode[i] * (cumSum[sz - 1] - cumSum[i]);

    return ans;
}