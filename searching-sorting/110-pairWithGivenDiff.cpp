/*


Find Pair Given Difference
Easy Accuracy: 49.01% Submissions: 12997 Points: 2

Given an array Arr[] of size L and a number N, you need to write a program to find if there exists a pair of elements in the array whose difference is N.

Example 1:

Input:
L = 6, N = 78
arr[] = {5, 20, 3, 2, 5, 80}
Output: 1
Explanation: (2, 80) have difference of 78.

Example 2:

Input:
L = 5, N = 45
arr[] = {90, 70, 20, 80, 50}
Output: -1
Explanation: There is no pair with difference of 45.

Your Task:
You need not take input or print anything. Your task is to complete the function findPair() which takes array arr, size of the array L and N as input parameters and returns True if required pair exists, else return False.

Expected Time Complexity: O(L* Log(L)).
Expected Auxiliary Space: O(1).

Constraints:
1 ≤ L ≤ 104
1 ≤ Arr[i], N ≤ 105

*/

bool findPair(int arr[], int size, int n)
{

    sort(arr, arr + size);

    int smallEleIndex = 0;
    int largeEleIndex = 1;

    while (largeEleIndex < size)
    {
        int diff = arr[largeEleIndex] - arr[smallEleIndex];

        if (diff == n)
            return true;

        else if (diff > n)
            smallEleIndex++;

        else
            largeEleIndex++;
    }

    return false;
}