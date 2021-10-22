#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
    ll test;
    cin >> test;
    while (test--)
    {
        ll n, i;
        cin >> n;
        ll a[n];
        ll b[n - 1];
        for (i = 0; i < n; i++)
            cin >> a[i];
        for (i = 0; i < n - 1; i++)
            cin >> b[i];
        sort(a, a + n);
        sort(b, b + n - 1);
        map<ll, ll> m;

        for (i = 0; i < n - 1; i++)
        {
            ll p = b[i] - a[i];
            ll q = b[i] - a[i + 1];
            if (p != q)
            {
                if (p > 0)
                    m[p]++;
                if (q > 0)
                    m[q]++;
            }
            else
            {
                if (p > 0)
                    m[p]++;
            }
        }
        for (auto pr : m)
        {
            if (pr.second == n - 1)
            {
                cout << pr.first << endl;
                break;
            }
        }
    }
}