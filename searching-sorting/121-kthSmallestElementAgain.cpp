#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, q;
        cin >> n >> q;

        vector<pair<int, int>> v;

        while (n--)
        {
            int a, b;
            cin >> a >> b;

            v.push_back({a, b});
        }

        sort(v.begin(), v.end());

        // merge
        int idx = 0;
        for (int i = 0; i < v.size(); i++)
        {
            if (v[idx].second >= v[i].first)
                v[idx].second = max(v[idx].second, v[i].second);
            else
            {
                idx++;
                v[idx] = v[i];
            }
        }

        while (q--)
        {
            int k;
            cin >> k;
            int ans = -1;
            for (int i = 0; i <= idx; i++)
            {
                if ((v[i].second - v[i].first + 1) >= k)
                {
                    ans = v[i].first + k - 1;
                    break;
                }
                else
                {
                    k = k - (v[i].second - v[i].first + 1);
                }
            }

            cout << ans << endl;
        }
    }
    return 0;
}
