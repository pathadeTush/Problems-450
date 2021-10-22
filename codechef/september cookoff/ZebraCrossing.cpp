#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve()
{
    ll n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    char res = s[0];
    int cnt = 0;
    for (int i = 1; i < n; i++)
    {
        if (res != s[i])
        {
            cnt++;
            res = s[i];
        }
    }

    if (cnt < k)
    {
        cout << -1 << "\n";
        return;
    }
    if (s[0] == '0')
    {
        if (k % 2)
        {
            for (int i = s.size() - 1; i >= 0; i--)
            {
                if (s[i] == '1')
                {
                    cout << i + 1 << "\n";
                    return;
                }
            }
        }
        else
        {
            for (int i = s.size() - 1; i >= 0; i--)
            {
                if (s[i] == '0')
                {
                    cout << i + 1 << "\n";
                    return;
                }
            }
        }
    }
    else
    {
        if (k % 2)
        {
            for (int i = s.size() - 1; i >= 0; i--)
            {
                if (s[i] == '0')
                {
                    cout << i + 1 << "\n";
                    return;
                }
            }
        }
        else
        {
            for (int i = s.size() - 1; i >= 0; i--)
            {
                if (s[i] == '1')
                {
                    cout << i + 1 << "\n";
                    return;
                }
            }
        }
    }
}

int main()
{
    //fast input and output
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}