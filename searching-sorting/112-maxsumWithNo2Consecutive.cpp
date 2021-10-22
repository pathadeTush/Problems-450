class Solution
{
public:
    //Function to find the maximum money the thief can get.
    int FindMaxSum(int arr[], int n)
    {
        if (n <= 0)
            return 0;
        if (n == 1)
            return arr[0];
        if (n == 2)
            return max(arr[0], arr[1]);

        int dp[n]; // dp[i] will store the max sum till i

        dp[0] = arr[0];
        dp[1] = max(arr[0], arr[1]);

        for (int i = 2; i < n; i++)
        {

            // for each arr[i] we have two choice whether to include it or not
            // if we are taking dp[i-1] in our ans then we can't include arr[i] in our ans.
            // if we are taking dp[i-2] in our ans then we can include arr[i] in our ans
            // maxsum till i  = max(maxsum till i-1, maxsum till i-2 + arr[i])
            dp[i] = max(dp[i - 1], dp[i - 2] + arr[i]);
        }

        return dp[n - 1];
    }
};