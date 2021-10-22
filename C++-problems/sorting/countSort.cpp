#include <bits/stdc++.h>
using namespace std;

// To create an array of appropriate range: O(max(Ai))
// To store the count of each element : O(n)
// To traverse count array: O(max(Ai))
// Time complexity: O(max(Ai, n))


void countSort(int arr[], int n)
{
    if (n == 0 || n == 1)
        return;

    int maxEle = arr[0];
    for (int i = 1; i < n; i++)
        maxEle = max(maxEle, arr[i]);

    int count[20] = {0}; // stores the count of each element in an array
    for (int i = 0; i < n; i++)
        count[arr[i]]++;

    // update count of each element by adding previous elements count in that.
    for (int i = 1; i <= maxEle; i++)
        count[i] += count[i - 1];

    // decrement count of arr[i] by one and store arr[i] at count[arr[i]] index of ans array
    int ans[n];
    for (int i = n - 1; i >= 0; i--)
        ans[--count[arr[i]]] = arr[i];

    // copy ans to arr
    for (int i = 0; i < n; i++)
        arr[i] = ans[i];

    return;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    countSort(arr, n);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}