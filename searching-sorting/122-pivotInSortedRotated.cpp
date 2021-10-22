#include <bits/stdc++.h>
using namespace std;

/*
Problem Statement – Suppose we have a sorted array, and now we rotate it N times, find the pivot element. The pivot element would be the smallest element. Also, can you calculate N?

Clues –

    Solution should be O(log N) in time and O(1) in space.
    Can you think of  a binary search based solution where you keep comparing the middle element with the last element?

logic:
1. Clearly our ans is position of snallest element in a array.
2. We can do it in O(n)
3. Apply Binary Search to optimize it. Note here we have to search for smallest element
4. If a[mid] > a[high]  then largest element will lye in right part
    else it will lye in left part
5. If a[mid] < a[high], then largest element will lye in left part
    else it will lye in right part
6. If a[mid] == a[high]  return mid;
*/

int getPivot(int arr[], int n)
{

    if (n == 0 || n == 1)
        return -1;

    // check if array is not rotated
    if (arr[0] <= arr[n - 1])
        return -1;

    int low = 0;
    int high = n - 1;
    int mid;

    while (low < high)
    {
        mid = (low + high) >> 1;

        if (arr[mid] > arr[high])
            low = mid + 1;
        else
            high = mid; // not mid-1 because in that case we are loosing midth element. It also might be pivot
    }

    return low; // here low = mid = high
}

int main()
{
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int ans = getPivot(arr, n);
    cout << ans;

    return 0;
}