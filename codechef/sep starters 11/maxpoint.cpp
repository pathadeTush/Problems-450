#include <bits/stdc++.h>
using namespace std;

long long knapsack(int n, int w, int val[], int wt[], vector<vector<long long>> &dp, int totQ[])
{
  if (n == 0 or w == 0)
    return 0;

  if (dp[n][w] != -1)
    return dp[n][w];

  if (wt[n - 1] <= w and totQ[(n - 1) % 3] < 20)
  {
    totQ[(n - 1) % 3]++;
    long long inc = val[n - 1] + knapsack(n, w - wt[n - 1], val, wt, dp, totQ);
    long long exc = knapsack(n - 1, w, val, wt, dp, totQ);
    if(inc >= exc){
      return dp[n][w] = inc;
    }
    else{
      totQ[(n - 1) % 3]--;
      return dp[n][w] = exc;
    }
  }
  else
  {
    return dp[n][w] = knapsack(n - 1, w, val, wt, dp, totQ);
  }
}

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int ta, tb, tc, pa, pb, pc;
    cin >> ta >> tb >> tc >> pa >> pb >> pc;
    int W = 240;

    int val[3] = {pa, pb, pc};
    int wt[3] = {ta, tb, tc};
    int totQ[3] = {0};

    vector<vector<long long>> dp(4, vector<long long>(W + 1, -1));

    cout << knapsack(3, W, val, wt, dp, totQ) << endl;
  }
  return 0;
}

// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//   int t;
//   cin >> t;
//   while (t--)
//   {
//     int ta, tb, tc, pa, pb, pc;
//     cin >> ta >> tb >> tc >> pa >> pb >> pc;
//     long long int ans = 0, sum = 0;

//     int mx = max(pa, max(pb, pc));
//     int t = 240;
//     int na = t / pa;
//     if(na >= 20){
//       ans = pa * 20;
//       t = 240 - ta * 20;
//       sum = ans;
//     }
//     else{
//       ans = na * pa;
//       sum = ans;
//       t = ta * na;
//     }


//   }
//   return 0;
// }