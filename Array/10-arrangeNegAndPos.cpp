#include <iostream>
using namespace std;

void arrangeNegPos(int arr[], int n)
{

    int l = 0, r = n - 1;

    while (l < r)
    {
        while (arr[l] < 0)
            l++;
        while (arr[r] >= 0)
            r--;

        if (l < r)
        {
            int temp = arr[l];
            arr[l] = arr[r];
            arr[r] = temp;
        }
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

    arrangeNegPos(arr, n);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}