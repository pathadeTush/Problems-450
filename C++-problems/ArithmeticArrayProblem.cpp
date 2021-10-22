/*
problem: An arithmetic array is an array that contains at least two integers and the differences between consecutive integers are equal. For ex, [9,10], [3,3,3] and [9,5,7,3].

Determine the length of longest contigous arithmetic subarray.

1 sec = 10^18 operation (approx)
maximum array size possible for competitive programming: 10^8
*/

#include <bits/stdc++.h>
using namespace std;

// int main()
// {
//     int n;
//     cin >> n;
//     int arr[n];

//     for (int i = 0; i < n; i++)
//         cin >> arr[i];

//     int max = 0, diff, k;

//     for (int i = 0; i < n-1; i++)
//     {
//         diff = abs(arr[i] - arr[i+1]);
//         k = 1;
//         for (int j = i+1; j < n-1; j++)
//         {
//             if (abs(arr[j] - arr[j+1]) == diff)
//                 k++;
//             else
//                 break;
//         }
//         if (k > max)
//             max = k;
//     }
//     cout << max+1;

//     return 0;
// }

// O(n) soln
int main()
{
    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int ans = 0, current = 1, prevDiff = abs(arr[0] - arr[1]);


    for (int i = 1; i < n - 1; i++)
    {
        if (abs(arr[i] - arr[i + 1]) == prevDiff)
            current++;
        else
        {
            ans = max(ans, current);
            current = 1;
            prevDiff = abs(arr[i] - arr[i + 1]);
        }
    }
    cout << ans+1;

    return 0;
}