/*


Count triplets with sum smaller than X
Medium Accuracy: 49.96% Submissions: 13145 Points: 4

Given an array arr[] of distinct integers of size N and a sum value X, the task is to find count of triplets with the sum smaller than the given sum value X.


Example 1:

Input: N = 4, X = 2
arr[] = {-2, 0, 1, 3}
Output:  2
Explanation: Below are triplets with 
sum less than 2 (-2, 0, 1) and (-2, 0, 3). 

Example 2:

Input: N = 5, X = 12
arr[] = {5, 1, 3, 4, 7}
Output: 4
Explanation: Below are triplets with 
sum less than 12 (1, 3, 4), (1, 3, 5), 
(1, 3, 7) and (1, 4, 5).


Your Task:
This is a function problem. You don't need to take any input, as it is already accomplished by the driver code. You just need to complete the function countTriplets() that take array arr[], integer N  and integer X as parameters and returns the count of triplets.


Expected Time Complexity: O(N2).
Expected Auxiliary Space: O(1).


Constraints:
3 ≤ N ≤ 103
*/

long long countTriplets(long long arr[], int n, long long sum)
{
    sort(arr, arr + n); // do sorting to solve such problems. So that we can apply two pointer approach
    // to optimize it.

    long long int count = 0;

    for (int i = 0; i < n; i++)
    {
        int l = i + 1;
        int r = n - 1;

        while (l < r)
        {
            if (arr[i] + arr[l] + arr[r] < sum)
            {
                count += r - l; // all (l, l+1), (l, l+2), ....(l, r) will satisfy above condition as array is sorted
                l++;
            }
            else
                r--;
        }
    }

    return count;
}