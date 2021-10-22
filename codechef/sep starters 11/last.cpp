#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    // your code goes here
    ll t;
    cin >> t;

    while (t--)
    {
        ll n;
        cin >> n;
        ll power[n + 1], arr[n+1];
        map<ll, ll> ans;

        for (ll i = 1; i <= n; i++){
            cin >> power[i];
            arr[i] = i;
        }

        for (ll i = 1; i <= n; i++)
        {
            ans[arr[i]] = i;

            for (ll j = i + 1; j < n; j++)
            {
                if (power[arr[j]] < power[arr[j + 1]])
                {
                    swap(arr[j], arr[j + 1]);
                }
            }
        }

        for (ll i = 1; i <= n; i++)
            cout << ans[i] << " ";
        cout << "\n";
    }
    return 0;
}
