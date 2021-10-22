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

    //Function to find minimum time required to rot all oranges.
    int orangesRotting(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int, int>> que;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 2)
                    que.push({i, j});
            }
        }
        que.push({-1, -1}); // delimeter

        bool isChanged = true;
        int Time = 0;
        while (isChanged)
        {
            isChanged = false;

            while (que.front().first != -1 and que.front().second != -1)
            {
                int x = que.front().first;
                int y = que.front().second;
                que.pop();

                //cout << x << " " << y << endl;

                if (isSafe(x - 1, y, n, m) and grid[x-1][y] == 1)
                {
                    if (!isChanged)
                        Time++;
                    isChanged = true;
                    grid[x - 1][y] = 2;
                    que.push({x - 1, y});
                }
                if (isSafe(x + 1, y, n, m) and grid[x+1][y] == 1)
                {
                    if (!isChanged)
                        Time++;
                    isChanged = true;
                    grid[x + 1][y] = 2;
                    que.push({x + 1, y});
                }
                if (isSafe(x, y - 1, n, m) and grid[x][y-1] == 1)
                {
                    if (!isChanged)
                        Time++;
                    isChanged = true;
                    grid[x][y - 1] = 2;
                    que.push({x, y - 1});
                }
                if (isSafe(x, y + 1, n, m) and grid[x][y+1] == 1)
                {
                    if (!isChanged)
                        Time++;
                    isChanged = true;
                    grid[x][y + 1] = 2;
                    que.push({x, y + 1});
                }
            }
            que.pop();
            que.push({-1, -1});
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)
                    return -1;
            }
        }

        return Time;
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
        int ans = obj.orangesRotting(grid);
        cout << ans << "\n";
    }
    return 0;
} // } Driver Code Ends