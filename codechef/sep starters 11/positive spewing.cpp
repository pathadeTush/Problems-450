#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
  ll t;
  cin >> t;
  while (t--)
  {
    ll n, k;
    cin >> n >> k;
    vector<ll> arr(n);

    map<ll, ll> mp;

    for (ll i = 0; i < n; i++)
    {
      cin >> arr[i];
      mp[i] = arr[i];
    }

    for (ll j = 0; j < k; j++)
    {
      for (ll i = 0; i < n; i++)
      {
        if (mp[i] > 0)
        {
          if (i == 0)
          {
            arr[n - 1]++;
            arr[i + 1]++;
          }
          else if (i == n-1)
          {
            arr[0]++;
            arr[i - 1]++;
          }
          else
          {
            arr[i - 1]++;
            arr[i + 1]++;
          }
        }
      }

      for (ll i = 0; i < n; i++)
        mp[i] = arr[i];
    }

    ll sum = 0;
    for (ll i = 0; i < n; i++)
      sum += arr[i];

    cout << sum << "\n";
  }

  return 0;
}