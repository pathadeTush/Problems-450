#include <bits/stdc++.h>
using namespace std;

#define ll long long

inline bool isSafe(int i, int j, int n, int m)
{
   if (i >= 1 and j >= 1 and i <= n and j <= m)
      return true;
   return false;
}

ll knapsack(int i, int j, int n, int m, int x, int y, vector<vector<long long>> &dp)
{
   if (i == n and j == m)
   {
      return dp[i][j];
   }

   int dx[] = {0, 1, 1};
   int dy[] = {1, 1, 0};
   int val[] = {x, y, x};

   for (int i = 0; i < 3; i++)
   {
      int I = i + dx[i];
      int J = j + dy[i];
      if (isSafe(I, J, n, m))
      {
         dp[I][J] = min(dp[I][J], val[i] + knapsack(I, J, n, m, x, y, dp));
      }
   }

   return dp[n][m];
}

int main()
{
   int t;
   cin >> t;
   while (t--)
   {
      ll n, m, x, y;
      cin >> n >> m >> x >> y;
      vector<vector<ll>> dp(n + 1, vector<ll>(m + 1, INT_MAX));

      cout << knapsack(1, 1, n, m, x, y, dp) << endl;
   }
   return 0;
}