/*

Minimum cost to fill given weight in a bag
Medium Accuracy: 45.25% Submissions: 15954 Points: 4

Given an array cost[] of positive integers of size N and an integer W, cost[i] represents the cost of ‘i’ kg packet of oranges, the task is to find the minimum cost to buy W kgs of oranges. If it is not possible to buy exactly W kg oranges then the output will be -1

Note:
1. cost[i] = -1 means that ‘i’ kg packet of orange is unavailable
2. It may be assumed that there is infinite supply of all available packet types.

Example 1:

Input: N = 5, arr[] = {20, 10, 4, 50, 100}
W = 5
Output: 14
Explanation: choose two oranges to minimize 
cost. First orange of 2Kg and cost 10. 
Second orange of 3Kg and cost 4. 

Example 2:

Input: N = 5, arr[] = {-1, -1, 4, 3, -1}
W = 5
Output: -1
Explanation: It is not possible to buy 5 
kgs of oranges


Your Task:  
You don't need to read input or print anything. Complete the function minimumCost() which takes N, W, and array cost as input parameters and returns the minimum value.

Expected Time Complexity: O(N*W)
Expected Auxiliary Space: O(N*W)

Constraints:
1 ≤ N, W ≤ 103
-1 ≤ cost[i] ≤ 105
cost[i] ≠ 0
*/

/**
 * @brief Logic: Same as unbounded knapsack but here minimize cost and also check if it is possible or not 
 * 
 */

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
#include <bits/stdc++.h>
using namespace std;
//Position this line where user code will be pasted.

class Solution
{

public:
    int fillBag(int cost[], int n, int w, vector<vector<int>> &dp)
    {
        if (w == 0)
            return 0;
        if (n <= 0)
            return -1;

        if (dp[n][w] != 0)
            return dp[n][w];

        if (cost[n - 1] != -1 and n <= w)
        {
            int include = fillBag(cost, n, w - n, dp);
            int exclude = fillBag(cost, n - 1, w, dp);

            if (include == -1 and exclude == -1)
                dp[n][w] = -1;
            else if (include == -1)
                dp[n][w] = exclude;
            else if (exclude == -1)
                dp[n][w] = cost[n - 1] + include;
            else
                dp[n][w] = min(cost[n - 1] + include, exclude);
            return dp[n][w];
        }
        else
            return dp[n][w] = fillBag(cost, n - 1, w, dp);
    }

    int minimumCost(int cost[], int n, int w)
    {
        vector<vector<int>> dp(n + 1, vector<int>(w + 1, 0));
        return fillBag(cost, n, w, dp);
    }
};

// { Driver Code Starts.
int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n, w;
        cin >> n >> w;

        int a[n];

        for (int i = 0; i < n; i++)
            cin >> a[i];

        Solution ob;
        cout << ob.minimumCost(a, n, w) << "\n";
    }
    return 0;
} // } Driver Code Ends
