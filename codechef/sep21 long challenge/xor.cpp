#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{

    ll t;
    cin >> t;

    while (t--)
    {
        ll n, x;
        cin >> n >> x;
        unordered_map<ll, ll> mp1; // (value, freq)
        unordered_map<ll, ll> mp2; // (value, freq after xor)
        vector<ll> arr(n);

        for (ll i = 0; i < n; i++)
        {
            cin >> arr[i];
            mp1[arr[i]]++;
        }

        for (ll i = 0; i < n; i++)
        {
            mp2[arr[i] ^ x]++;
        }

        ll maxFreq = -1, origFreq = INT_MAX;

        for (auto it : mp1)
        {
            if (maxFreq < it.second + mp2[it.first])
            {
                maxFreq = it.second + mp2[it.first];
                origFreq = it.second;
            }
            else if (maxFreq == it.second + mp2[it.first])
            {
                origFreq = min(origFreq, it.second);
            }
        }
        for (auto it : mp2)
        {
            if (!mp1[it.first])
            {
                if (maxFreq < it.second + mp1[it.first])
                {
                    maxFreq = it.second + mp1[it.first];
                    origFreq = 0;
                }
            }
        }

        // for (ll i = 0; i < n; i++){
        //     if(maxFreq <= mp1[arr[i]] + mp2[arr[i]]){
        //         maxFreq = mp1[arr[i]] + mp2[arr[i]];
        //         origFreq = min(origFreq, mp1[arr[i]]);
        //     }
        // }

        cout << maxFreq << " " << maxFreq - origFreq << endl;
    }

    return 0;
}
