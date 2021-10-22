// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
private:
    typedef struct node
    {
        int x, y;
        int dist;
        node(int i, int j, int d)
        {
            x = i;
            y = j;
            dist = d;
        }
    } node;

public:
    inline bool
    isSafe(int x, int y, int n)
    {
        if (x >= 1 and y >= 1 and x <= n and y <= n)
            return true;
        return false;
    }
    //Function to find out minimum steps Knight needs to reach target position.
    int minStepToReachTarget(vector<int> &KnightPos, vector<int> &TargetPos, int n)
    {
        vector<vector<int>> vis(n + 1, vector<int>(n + 1, 0));

        queue<node> q;
        q.push(node(KnightPos[0], KnightPos[1], 0));
        vis[KnightPos[0]][KnightPos[1]] = 1;

        while (!q.empty())
        {
            node curr = q.front();
            q.pop();
            if (curr.x == TargetPos[0] and curr.y == TargetPos[1])
                return curr.dist;

            int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
            int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

            for (int i = 0; i < 8; i++)
            {
                int X = curr.x + dx[i];
                int Y = curr.y + dy[i];

                if (isSafe(X, Y, n) and !vis[X][Y])
                {
                    vis[X][Y] = 1;
                    q.push(node(X, Y, curr.dist + 1));
                }
            }
        }

        return -1;
    }
};
// { Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        vector<int> KnightPos(2);
        vector<int> TargetPos(2);
        int N;
        cin >> N;
        cin >> KnightPos[0] >> KnightPos[1];
        cin >> TargetPos[0] >> TargetPos[1];
        Solution obj;
        int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
        cout << ans << "\n";
    }
    return 0;
} // } Driver Code Ends