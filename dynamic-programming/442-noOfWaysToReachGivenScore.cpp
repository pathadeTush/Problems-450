/*

Reach a given score
Easy Accuracy: 71.34% Submissions: 8779 Points: 2

Consider a game where a player can score 3 or 5 or 10 points in a move. Given a total score n, find number of distinct combinations to reach the given score.

Example:
Input
3
8
20
13
Output
1
4
2
Explanation
For 1st example when n = 8
{ 3, 5 } and {5, 3} are the 
two possible permutations but 
these represent the same 
cobmination. Hence output is 1.

Your Task:  
You don't need to read input or print anything. Your task is to complete the function count( ) which takes N as input parameter and returns the answer to the problem.

Constraints:
1 ≤ T ≤ 100
1 ≤ n ≤ 1000
*/

/**
 * @brief Logic: Same as subset sum problem
 * 
 */

// { Driver Code Starts
// Driver Code
#include <bits/stdc++.h>
#define ll long long int
using namespace std;

// } Driver Code Ends

long long int solve(int arr[], int n, int sum, vector<vector<long long>> &dp)
{
    if (sum == 0)
        return 1;
    if (n <= 0)
        return 0;

    if (dp[n][sum] != -1)
        return dp[n][sum];
    
    if(arr[n-1] <= sum){
       return dp[n][sum] = solve(arr, n, sum - arr[n - 1], dp) + solve(arr, n - 1, sum, dp);
    }
    else{
        return dp[n][sum] = solve(arr, n-1, sum, dp);
    }
}

// Complete this function
long long int count(long long int n)
{
    int arr[3] = {3, 5, 10};
    vector<vector<long long>> dp(4, vector<long long>(n + 1, -1));
    return solve(arr, 3, n, dp);
}

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        cout << count(n) << endl;
    }
    return 0;
} // } Driver Code Ends