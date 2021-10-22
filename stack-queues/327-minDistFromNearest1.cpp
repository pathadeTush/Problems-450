// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    bool isSafe(int x, int y, int n, int m)
    {
        if (x >= 0 and x < n and y >= 0 and y < m)
            return true;
        return false;
    }

    //Function to find distance of nearest 1 in the grid for each cell.
    vector<vector<int>> nearest(vector<vector<int>> grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        // initialize all value of ans to INT_MAX
        vector<vector<int>> ans(n, (vector<int>(m, INT_MAX)));
        queue<pair<int, int>> que;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)
                {
                    ans[i][j] = 0; // make value to 0 for which ans[i][j] = 1 as thier dist is 0
                    que.push({i, j});
                }
            }
        }

        while (!que.empty())
        {
            int x = que.front().first;
            int y = que.front().second;
            que.pop();

            vector<pair<int, int>> moves = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

            for (auto move : moves)
            {
                int nx = x + move.first;
                int ny = y + move.second;

                // second condition will work as not visited
                if (isSafe(nx, ny, n, m) and ans[nx][ny] > ans[x][y] + 1)
                {
                    ans[nx][ny] = ans[x][y] + 1;
                    que.push({nx, ny});
                }
            }
        }

        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        vector<vector<int>> ans = obj.nearest(grid);
        for (auto i : ans)
        {
            for (auto j : i)
            {
                cout << j << " ";
            }
            cout << "\n";
        }
    }
    return 0;
} // } Driver Code Ends