#include <bits/stdc++.h>
using namespace std;

// assumed src is 0
int n;
int visited_all;

int tsp(int src, int mask, vector<vector<int>> grp, vector<vector<int>> &dp)
{
    if (mask == visited_all)
        return grp[src][0];

    // memoization
    if (dp[mask][src] != -1)
        return dp[mask][src];

    int ans = INT_MAX;
    for (int city = 0; city < n; city++)
    {
        // if not visited
        if (((mask & (1 << city)) == 0) and grp[src][city] != 0)
        {
            //cout << "src " << src << "  ans: " << ans << endl;
            // mask = mask | (1 << city); // mark visited
            //cout << "src: " << src+1 << "   city: " << city+1 << endl;
            int newDist = grp[src][city] + tsp(city, mask | (1 << city), grp, dp);
            //cout << "newDist: " << newDist << "  ans: " << ans;
            ans = min(ans, newDist);
        }
    }

    return (dp[mask][src] = ans);
}

int main()
{
    cin >> n;

    vector<vector<int>> grp(n, vector<int>(n));
    vector<vector<int>> dp(1 << n, vector<int>(n, -1)); // 2^n x n

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> grp[i][j];

    visited_all = (1 << n) - 1;
    cout << tsp(0, 1, grp, dp) << endl; // 1 as marking 0 as visited

    return 0;
}