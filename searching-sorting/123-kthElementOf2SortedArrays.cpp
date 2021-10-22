#include <bits/stdc++.h>
using namespace std;

int eleLessThanOrEqualTo(int arr[], int n, int ele)
{
    int low = 0;
    int high = n - 1;

    while (low <= high)
    {
        int mid = (low + high) >> 1;

        if (arr[mid] > ele)
            high = mid - 1;

        else
            low = mid + 1;
    }

    return low;
}

int kthElement(int arr1[], int arr2[], int n, int m, int k)
{
    int low = min(arr1[0], arr2[0]);
    int high = max(arr1[n - 1], arr2[m - 1]);

    while (low <= high)
    {
        int mid = (low + high) >> 1;

        int count = 0;

        count += eleLessThanOrEqualTo(arr1, n, mid);
        count += eleLessThanOrEqualTo(arr2, m, mid);

        // don't return mid from here becoz that mid might not be present in arrays

        if (count < k)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return low;
}