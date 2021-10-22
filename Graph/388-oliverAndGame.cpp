/*
Oliver and Bob have decided to play Hide and Seek taking the entire city as their arena. In the given scenario of the game, it's Oliver's turn to hide and Bob is supposed to find him.
Oliver can hide in any of the houses in the city including the King's Mansion. As Bob is a very lazy person, for finding Oliver, he either goes towards the King's Mansion (he stops when he reaches there), or he moves away from the Mansion in any possible path till the last house on that path.

Oliver runs and hides in some house (say X) and Bob is starting the game from his house (say Y). If Bob reaches house X, then he surely finds Oliver.

Given Q queries, you need to tell Bob if it is possible for him to find Oliver or not.

The queries can be of the following two types:
0 X Y : Bob moves towards the King's Mansion.
1 X Y : Bob moves away from the King's Mansion

INPUT :
The first line of the input contains a single integer N, total number of houses in the city. Next N-1 lines contain two space separated integers A and B denoting a road between the houses at address A and B.
Next line contains a single integer Q denoting the number of queries.
Following Q lines contain three space separated integers representing each query as explained above.

OUTPUT :
Print "YES" or "NO" for each query depending on the answer to that query.

CONSTRAINTS :
1 ≤ N ≤ 10^5
1 ≤ A,B ≤ N
1 ≤ Q ≤ 5*10^5
1 ≤ X,Y ≤ N

NOTE :
Large Input size. Use printf scanf or other fast I/O methods.

Sample Input

9
1 2
1 3
2 6
2 7
6 9
7 8
3 4
3 5
5
0 2 8
1 2 8
1 6 5
0 6 5
1 9 1

Sample Output

YES

NO

NO

NO

YES
*/
// #include <bits/stdc++.h>
// using namespace std;

// void dfs(int src, vector<int> adj[], vector<bool> &vis, map<int, int> &mp)
// {
//     vis[src] = true;
//     for (auto it : adj[src])
//     {
//         if (!vis[it])
//         {
//             mp[it] = src;
//             dfs(it, adj, vis, mp);
//         }
//     }
//     return;
// }

// inline bool find(int src, int x, vector<int> adj[], vector<bool> &vis)
// {
//     vis[src] = true;
//     if (src == x)
//         return true;
//     for (auto it : adj[src])
//     {
//         if (!vis[it] and it != 1)
//         {
//             bool canFind = find(it, x, adj, vis);
//             if (canFind)
//                 return true;
//         }
//         else if (it == 1)
//             return false;
//     }
//     return false;
// }

// int main()
// {
//     int n; // total no. of houses
//     cin >> n;

//     vector<int> adj[n + 1];
//     for (int i = 1; i < n; i++)
//     {
//         int a, b;
//         cin >> a >> b;
//         adj[a].push_back(b);
//         adj[b].push_back(a);
//     }
//     map<int, int> mp; // (ele, nearest element in direction of 1)
//     mp[1] = 1;

//     vector<bool> vis(n + 1, false);

//     dfs(1, adj, vis, mp);

//     int q;
//     cin >> q;
//     while (q--)
//     {
//         int dir, x, y;
//         cin >> dir >> x >> y;

//         vis.clear();
//         vis = vector<bool>(n + 1, false);

//         if (dir == 0)
//         {
//             for (auto it : adj[y])
//             {
//                 if (it != mp[y])
//                     vis[it] = true;
//             }
//         }
//         else
//             vis[mp[y]] = true;
//         if (y == 1)
//         {
//             if (dir == 0 and x != 1)
//                 cout << "NO" << endl;
//             else
//                 cout << "YES" << endl;
//         }
//         else
//         {
//             bool canFind = find(y, x, adj, vis);
//             if (canFind)
//                 cout << "YES" << endl;
//             else
//                 cout << "NO" << endl;
//         }
//     }

//     return 0;
// }

/**
 * @file 388-oliverAndGame.cpp  
 * @author Tushar Pathade (you@domain.com)
 * @brief Use Euler Tour Logic and check if x is in subtree of y or not
 * @version 0.1
 * @date 2021-07-31
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <bits/stdc++.h>
using namespace std;

int timer = 0;

void dfs(int src, vector<int> adj[], vector<bool> &vis, int startTime[], int endTime[])
{
    startTime[src] = timer++;
    vis[src] = true;
    for (auto it : adj[src])
    {
        if (!vis[it])
        {
            dfs(it, adj, vis, startTime, endTime);
        }
    }
    endTime[src] = timer++;
    return;
}

inline bool isSubtree(int x, int y, int startTime[], int endTime[])
{
    if (startTime[x] > startTime[y] and endTime[x] < endTime[y])
        return true;
    return false;
}

int main()
{
    int n; // total no. of houses
    scanf("%d", &n);

    vector<int> adj[n + 1];
    for (int i = 1; i < n; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<bool> vis(n + 1, false);
    int startTime[n + 1], endTime[n + 1];
    dfs(1, adj, vis, startTime, endTime); // store startTime and endTime for each element w.r.to 1

    int q;
    scanf("%d", &q);
    while (q--)
    {
        int dir, x, y;
        scanf("%d %d %d", &dir, &x, &y);
        if (!isSubtree(x, y, startTime, endTime) and !isSubtree(y, x, startTime, endTime))
        {
            printf("NO\n");
            continue;
        }
        if (dir == 1) // opposite to 1    check if x is subtree of y or not
        {
            if (isSubtree(x, y, startTime, endTime))
                printf("YES\n");
            else
                printf("NO\n");
        }
        // towards 1 check if y is subtree of x
        else
        {
            if (isSubtree(y, x, startTime, endTime))
                printf("YES\n");
            else
                printf("NO\n");
        }
    }

    return 0;
}