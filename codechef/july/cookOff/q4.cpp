#include <bits/stdc++.h>
using namespace std;
map<int, int> mp1;

bool comp(int a, int b)
{
    return (mp1[a] > mp1[b]);
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int arr[n];
        mp1.clear();
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            mp1[arr[i]]++;
        }
        int ans = 0;
        sort(arr, arr + n, comp);
        int p = 0;
        int prev = -1;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] != prev)
            {
                ans += mp1[arr[i]];
                k--;
            }
            if (k == 0)
                break;
            prev = arr[i];
        }

        if (mp1.size() <= k)
            cout << ans << endl;
        else
            cout << ans + 1 << endl;

        // cout << ans << endl;
    }
}