/*

Given an array of size n that has the following specifications:
    1. Each element is either a policemen or theif
    2. Each policemen can catch only 1 theif
    3. A policemen cannot catch a theif who is more than K unit away from the policemen


find the maximum number of theives that can be caught.

*/

#include <bits/stdc++.h>
using namespace std;


// O(n^2)
int theifCount(int arr[], int n, int k)
{
    if (n == 0 || n == 1)
        return 0;

    int visited[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
    }

    int count = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 1)
        {
            int j = i - k, found = 0;
            while (j >= 0 && j != i)
            {
                if (arr[j] == 0 && visited[j] != 1)
                {
                    count++;
                    visited[j] = 1;
                    found = 1;
                    break;
                }
                j++;
            }

            if (!found)
            {
                j = i+1;
                while (j < n && j <= i + k)
                {
                    if (arr[j] == 0 && visited[j] != 1)
                    {
                        count++;
                        visited[j] = 1;
                        break;
                    }
                    j++;
                }
            }
        }
    }

    return count;
}

int main()
{
    int n, k;
    cin >> n >> k;

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << theifCount(arr, n, k);

    return 0;
}