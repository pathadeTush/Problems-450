#include <bits/stdc++.h>
using namespace std;

// O(n)
void waveSort(int arr[], int n)
{
    if (n == 0 || n == 1)
        return;

    for (int i = 1; i < n;)
    {
        if (arr[i] > arr[i - 1])
            swap(arr[i], arr[i - 1]);

        if (i < n - 1 && arr[i] > arr[i + 1])
            swap(arr[i], arr[i + 1]);

        i += 2;
    }

    return;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    waveSort(arr, n);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}