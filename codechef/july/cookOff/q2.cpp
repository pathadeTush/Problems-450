#include<bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

long long func(long long x, long long y, long long ans, vector<vector<long long>> &dp)
{
    if (gcd(x, y) > 1)
    {
        return ans;
    }
    if (dp[x][y])
        return dp[x][y];

    dp[x][y] = min(func(x + 1, y, ans + 1, dp), func(x, y + 1, ans + 1, dp));
    return dp[x][y];
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        vector<vector<long long>> dp(1000000000, vector<long long>(1000000000, 0));

        long long x, y, ans = 0;
        cin >> x >> y;
        cout << func(x, y, ans, dp) << endl;
    }
    return 0;
}
