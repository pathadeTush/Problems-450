/*

Problem: check if there exist two elements in an array such that their sum is equal to given k
*/

#include <bits/stdc++.h>
using namespace std;

// O(n) but required sorted array
bool pairsum(int arr[], int n, int k)
{

    int low = 0, high = n - 1;
    while (low < high)
    {
        if (arr[low] + arr[high] == k)
            return true;
        else if (arr[low] + arr[high] > k)
            high--;
        else
            low++;
    }
    return false;
}

int main()
{
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int k;
    cin >> k;

    cout << pairsum(arr, n, k);

    return 0;
}