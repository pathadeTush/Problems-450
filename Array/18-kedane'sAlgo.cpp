// arr: input array
// n: size of array
//Function to find the sum of contiguous subarray with maximum sum.
int maxSubarraySum(int arr[], int n)
{

    int maxSum = INT_MIN, sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sum < 0)
            sum = 0;
        maxSum = max(maxSum, sum);
    }

    return maxSum;
}