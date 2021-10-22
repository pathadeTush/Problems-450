/*

Coin Change
Medium Accuracy: 47.19% Submissions: 44480 Points: 4

Given a value N, find the number of ways to make change for N cents, if we have infinite supply of each of S = { S1, S2, .. , SM } valued coins.


Example 1:

Input:
n = 4 , m = 3
S[] = {1,2,3}
Output: 4
Explanation: Four Possible ways are:
{1,1,1,1},{1,1,2},{2,2},{1,3}.

Example 2:

Input:
n = 10 , m = 4
S[] ={2,5,3,6}
Output: 5
Explanation: Five Possible ways are:
{2,2,2,2,2}, {2,2,3,3}, {2,2,6}, {2,3,5} 
and {5,5}.


Your Task:
You don't need to read input or print anything. Your task is to complete the function count() which accepts an array S[] its size m and n as input parameter and returns the number of ways to make change for N cents.


Expected Time Complexity: O(m*n).
Expected Auxiliary Space: O(n).


Constraints:
1 <= n,m <= 103
*/

/**
 * @brief Logic same as knapsack. But it is unbounded knapsack means we can take 1 element many times.
 * 
 */

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    long long int coinChange(int arr[], int m, int sum, vector<vector<long long>> &dp)
    {
        if (sum == 0)
            return 1;
        if (m <= 0)
            return 0;

        if (dp[m][sum] != -1)
            return dp[m][sum];

        if (arr[m - 1] <= sum)
            //If we have taken any element then No need to do m-1 as we can take this element again
            return dp[m][sum] = (coinChange(arr, m, sum - arr[m - 1], dp) + coinChange(arr, m - 1, sum, dp));
        else
            return dp[m][sum] = coinChange(arr, m - 1, sum, dp);
    }

    long long int count(int S[], int m, int n)
    {
        vector<vector<long long>> dp(m + 1, vector<long long>(n + 1, -1));

        return coinChange(S, m, n, dp);
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int arr[m];
        for (int i = 0; i < m; i++)
            cin >> arr[i];
        Solution ob;
        cout << ob.count(arr, m, n) << endl;
    }

    return 0;
} // } Driver Code Ends