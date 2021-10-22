// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    void DFSRec(vector<vector<char>> &mat, int N, int M, int i, int j)
    {
        if (i >= 0 and i < N and j >= 0 and j < M and mat[i][j] == '1')
        {
            mat[i][j] = '2';

            DFSRec(mat, N, M, i, j + 1);
            DFSRec(mat, N, M, i, j - 1);
            DFSRec(mat, N, M, i - 1, j);
            DFSRec(mat, N, M, i + 1, j);
            DFSRec(mat, N, M, i + 1, j + 1);
            DFSRec(mat, N, M, i + 1, j - 1);
            DFSRec(mat, N, M, i - 1, j - 1);
            DFSRec(mat, N, M, i - 1, j + 1);
        }
    }

public:
    int numIslands(vector<vector<char>> &mat)
    {
        int count = 0;

        int N = mat.size();
        int M = mat[0].size();

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (mat[i][j] == '1')
                {
                    DFSRec(mat, N, M, i, j);

                    count++;
                }
            }
        }

        return count;
    }
};

// class Solution
// {
// public:
//     inline bool isSafe(int i, int j, int m, int n)
//     {
//         if (i >= 0 and j >= 0 and i < m and j < n)
//             return true;
//         return false;
//     }

//     void dfs(int x, int y, int m, int n, vector<vector<char>> grid, vector<<vector<bool>>&vis)
//     {
//         vis[x][y] = false;
//         //grid[x][y] = '0';
//         static int dx[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
//         static int dy[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };

//         for (int i = 0; i < 8; i++){
//             int X = x + dx[i];
//             int Y = y + dy[i];
//             if (isSafe(X, Y, m, n) and !vis[X][Y] and grid[X][Y] == '1')
//                 dfs(X, Y, m, n, grid, vis);

//         }
//         return;
//     }

//     //Function to find the number of islands.
//     int numIslands(vector<vector<char>> &grid)
//     {
//         int m = grid.size();
//         int n = grid[0].size();

//         vector<<vector<bool>>vis(501, vector<bool>(501, false));
//         //memset(vis, 0, sizeof(vis));

//         int totalIslands = 0;
//         for (int i = 0; i < m; i++)
//         {
//             for (int j = 0; j < n; j++)
//             {
//                 if (!vis[i][j] and grid[i][j] == '1')
//                 {
//                     dfs(i, j, m, n, grid, vis);
//                     totalIslands++;
//                 }
//             }
//         }

//         return totalIslands;
//     }
// };

// { Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
} // } Driver Code Ends