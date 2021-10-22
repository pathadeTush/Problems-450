// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int equalSubsetSum(int arr[], int n, int sum, vector<vector<int>>&dp)
    {
        if((n > 0 and sum == 0) or sum == 0)
            return 1;
        if (n <= 0)
            return 0;

        if(dp[n][sum] != -1)
            return dp[n][sum];

        if(sum >= arr[n-1]){
            return dp[n][sum] = (equalSubsetSum(arr, n - 1, sum - arr[n - 1], dp)) || (equalSubsetSum(arr, n - 1, sum, dp));
        }
        else{
            return dp[n][sum] = equalSubsetSum(arr, n - 1, sum, dp);
        }
    }

    int equalPartition(int N, int arr[])
    {
        int sum = 0;
        for (int i = 0; i < N; i++)
            sum += arr[i];

        if (sum & 1)
            return 0;

        sum = sum >> 1;
        vector<vector<int>> dp(N + 1, vector<int>(sum + 1, -1));

        return equalSubsetSum(arr, N, sum, dp);
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++)
            cin >> arr[i];

        Solution ob;
        if (ob.equalPartition(N, arr))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
} // } Driver Code Ends