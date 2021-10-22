/*

Rat in a Maze Problem - I
Medium Accuracy: 37.73% Submissions: 74057 Points: 4

Consider a rat placed at (0, 0) in a square matrix of order N * N. It has to reach the destination at (N - 1, N - 1). Find all possible paths that the rat can take to reach from source to destination. The directions in which the rat can move are 'U'(up), 'D'(down), 'L' (left), 'R' (right). Value 0 at a cell in the matrix represents that it is blocked and rat cannot move to it while value 1 at a cell in the matrix represents that rat can be travel through it.
Note: In a path, no cell can be visited more than one time.

Example 1:

Input:
N = 4
m[][] = {{1, 0, 0, 0},
         {1, 1, 0, 1}, 
         {1, 1, 0, 0},
         {0, 1, 1, 1}}
Output:
DDRDRR DRDDRR
Explanation:
The rat can reach the destination at 
(3, 3) from (0, 0) by two paths - DRDDRR 
and DDRDRR, when printed in sorted order 
we get DDRDRR DRDDRR.

Example 2:

Input:
N = 2
m[][] = {{1, 0},
         {1, 0}}
Output:
-1
Explanation:
No path exists and destination cell is 
blocked.

Your Task:  
You don't need to read input or print anything. Complete the function printPath() which takes N and 2D array m[ ][ ] as input parameters and returns the list of paths in lexicographically increasing order. 
Note: In case of no path, return an empty list. The driver will output "-1" automatically.

Expected Time Complexity: O((N2)4).
Expected Auxiliary Space: O(L * X), L = length of the path, X = number of paths.

Constraints:
2 ≤ N ≤ 5
0 ≤ m[i][j] ≤ 1
*/

// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

/*
D L R U -> lexicographical order
*/

class Solution
{
public:
    inline bool isSafe(int x, int y, int n)
    {
        if (x >= 0 and y >= 0 and x < n and y < n)
            return true;
        return false;
    }

    void solve(int x, int y, vector<vector<int>> m, int n, vector<vector<int>> &vis, string path, vector<string> &paths)
    {
        if (x == n - 1 and y == n - 1)
        {
            paths.push_back(path);
            return;
        }

        int dx[4] = {1, 0, 0, -1};
        int dy[4] = {0, -1, 1, 0};
        string moves = "DLRU";

        for (int i = 0; i < 4; i++)
        {
            int X = x + dx[i];
            int Y = y + dy[i];

            if (isSafe(X, Y, n) and !vis[X][Y] and m[X][Y])
            {
                vis[x][y] = 1;
                solve(X, Y, m, n, vis, path + moves[i], paths);
                vis[x][y] = 0;
            }
        }

        return;
    }

    vector<string> findPath(vector<vector<int>> &m, int n)
    {
        vector<string> paths;
        if (m[0][0] == 0)
            return paths;
        vector<vector<int>> vis(n, vector<int>(n, 0));
        solve(0, 0, m, n, vis, "", paths);

        return paths;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
    }
    return 0;
} // } Driver Code Ends