#include <bits/stdc++.h>
using namespace std;

// sieve eratosthenes approach

// starts marking from square of number because previous are already marked.

// [ 2, 3, 4, 5, 6, 7]
//   0, 0, 1, 0, 1, 0 

void primeInRange(int arr[], int lower, int upper)
{
    for (int i = lower; i <= upper; i++)
    {
        // if the number is unmarked and its square <= upper then marked arr[i ^ 2] and successive poition at a distance of i
        if (arr[i] == 0 && (i * i <= upper))
        {
            for (int j = i * i; j <= upper; j += i)
                arr[j] = 1; // marked as non prime
        }
    }

    return;
}

int main()
{
    int lower; // lower bound
    int upper; // upper bound

    cin >> lower >> upper;

    int *arr = (int *)calloc(sizeof(int), upper + 1);

    primeInRange(arr, lower, upper);

    for (int i = lower; i <= upper; i++)
        if (arr[i] == 0)
            cout << i << " ";

    return 0;
}