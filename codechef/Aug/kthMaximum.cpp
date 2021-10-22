#include <bits/stdc++.h>
using namespace std;

int main()
{
    // your code goes here
    int t;
    cin >> t;

    while (t--)
    {
        long long n, k;
        cin >> n >> k;

        long long arr[n];

        long long maxEle = INT_MIN;
        for (long long i = 0; i < n; i++)
        {
            cin >> arr[i];
            if (maxEle < arr[i])
            {
                maxEle = arr[i];
            }
        }

        // for (long long i = 0; i < n; i++)
        // {
        //     if (maxEle == arr[i])
        //     {
        //         indices.push_back(i);
        //         count++;
        //     }
        // }

        long long ans = 0;

        // for (auto it : indices)
        // {
        //     if(it+1 >= k)
        //         ans +=  n - it;
        // }

        for (long long i = k - 1; i < n; i++)
        {
            if (arr[i] == maxEle)
                ans += n - i;
        }
        cout << ans << endl;
    }
    return 0;
}
