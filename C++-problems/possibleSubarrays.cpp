/*
Subarray are array of any contiguous elements of an array.
Possible subarray of array of size n = C(n, 2)+n */

// Problem: Print all possible subarray for a given array

#include <bits/stdc++.h>
using namespace std;

// O(n^3)
/* int main()
{
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            for (int k = i; k <= j; k++)
                cout << arr[k] << " ";
            cout << endl;
        }
    }

    return 0;
}
 */
// Problem: Print maximum possible sum of subarray
// O(n^2)
/* 
int main()
{
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int maxSum = INT_MIN, sum;

    for (int i = 0; i < n; i++)
    {
        sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += arr[j];
            maxSum = max(maxSum, sum);
        }
    }

    cout << maxSum;

    return 0;
}
 */

// Problem: Print maximum possible sum of subarray using CUMULATIVE sum array. It stores the sum from starting to current index for each index
// O(n^2)
/* 
int main()
{
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int cumulativeSumArr[n + 1], sum, maxSum = INT_MIN;
    cumulativeSumArr[0] = 0;

    for (int i = 1; i <= n; i++)
        cumulativeSumArr[i] = cumulativeSumArr[i - 1] + arr[i-1];

    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            sum = cumulativeSumArr[j] - cumulativeSumArr[i-1];
            maxSum = max(maxSum, sum);
        }
    }

    cout << maxSum;

    return 0;
} */

// Problem: Print maximum possible sum of subarray using kadane's algo
// O(n)
int maxSumByKadaneAlgo(int arr[], int n)
{
    int maxSum = INT_MIN, currentSum = 0;

    for (int i = 0; i < n; i++)
    {
        currentSum += arr[i];
        if (currentSum < 0)
            currentSum = 0;

        maxSum = max(maxSum, currentSum);
    }

    return maxSum;
}

// int main()
// {
//     int n;
//     cin >> n;

//     int arr[n];
//     for (int i = 0; i < n; i++)
//         cin >> arr[i];

//     cout << maxSumByKadaneAlgo(arr, n);

//     return 0;
// }


// Problem: Print maximum possible sum of subarray for an Circular array
// O(n)
/*

Wrapping means we traverse a array in a circular fashion.

wrapped element = elements which are used in ans.(for wrapping case)
unwrapped element = elements which are not used in ans.(for wrapping case)

consider example:
1)  arr = [-1, 4, -6, 7, 5, -4]
--> here, maxSum = 12 (7 + 5)
    here we don't need to use the wrapped element. We have used unwrapped element 7 and 5 to get ans. In this case ans is same as for normal array.

2) arr = [4, -4, 6, -6, 10, -11, -2, 12]
--> here, maxSum = 22 (12 + 4 + (-4) + 6 + (-6) + 10)
    here we have to used the wrapped element to get correct ans. wrapped elements are 4, -4, 6, -6, 10, 12 and unwrapped are = -11, 2.
    Now, you can see, if we delete unwrapped element from array then ans = ans of normal array.
    OR ans = totalsum of array + abs(sum of unwrapped element).

    so, sum of unwrapped element = minSum of a subarray.
*/
int main()
{
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int nonWrapSum, wrapSum; // wrapSum is for circular subarray

    nonWrapSum = maxSumByKadaneAlgo(arr, n); // nonWrapSum is for normal subarray

    int totalSum = 0;

    for (int i = 0; i < n; i++)
    {
        totalSum += arr[i];
        arr[i] = -arr[i];
    }

    // wrapSum = totalsum of array - sum of unwrapped element(minSum)
    // here, we have changed the size of array elements so maxSumByKadaneAlgo(arr, n) will give a abs(minSum)
    wrapSum = totalSum + maxSumByKadaneAlgo(arr, n);

    cout << max(nonWrapSum, wrapSum);

    return 0;
}

