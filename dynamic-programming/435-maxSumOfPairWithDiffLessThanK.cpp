/*

Pairs with specific difference
Easy Accuracy: 77.66% Submissions: 4222 Points: 2

Given an array of integers arr[] and a number K.You can pair two numbers of the array if the difference between them is strictly less than K. The task is to find the maximum possible sum of such disjoint pairs. The Sum of P pairs is the sum of all 2P numbers of pairs.

 

Example 1:

Input  : 
arr[] = {3, 5, 10, 15, 17, 12, 9}
K = 4
Output : 
62
Explanation :
Then disjoint pairs with difference less
than K are, (3, 5), (10, 12), (15, 17)
max sum which we can get is 
3 + 5 + 10 + 12 + 15 + 17 = 62
Note that an alternate way to form 
disjoint pairs is,(3, 5), (9, 12), (15, 17)
but this pairing produces less sum.

 

Example 2:

Input  : 
arr[] = {5, 15, 10, 300}
K = 12
Output : 
25

 

Your Task:  
You don't need to read input or print anything. Your task is to complete the function maxSumPairWithDifferenceLessThanK() which takes the array arr[], its size N and an integer K as inputs and returns the maximum possible sum of disjoint pairs.

 

Expected Time Complexity: O(N. log(N))
Expected Auxiliary Space: O(N)

 

Constraints:
1 ≤ N ≤ 105
0 ≤ K ≤ 105
1 ≤ arr[i] ≤ 104
*/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    int maxSumPairWithDifferenceLessThanK(int arr[], int N, int K)
    {
        long long int ans = 0;

        sort(arr, arr + N);

        // find nearest element with wich ele can combined after sorting. And add this 2 ele to result

        int i = N - 1;
        while(i > 0)
        {
            if (arr[i] - arr[i - 1] < K)
            {
                ans += arr[i] + arr[i-1];
                i -= 2;
                //cout << ans << endl;
            }
            else
                i--;
        }
        // cout << ans << endl;
        return ans;
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

        int K;
        cin >> K;
        Solution ob;
        cout << ob.maxSumPairWithDifferenceLessThanK(arr, N, K) << endl;
    }
    return 0;
}
// } Driver Code Ends