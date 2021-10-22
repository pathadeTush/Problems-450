#include <bits/stdc++.h>
using namespace std;

int count(int n){
    int k = 1 + log2(n);
    int p = 1 << (k-1);
    int ans = 0;
    while (k--)
    {
        //cout << "p: " << p << endl;
        if (n & p)
        {
            ans++;
            n = n << 1;
        }
        else
            break;
    }
    return ans;
}

int main(){
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        long long arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        pair<int, int> res = {0, -1};
        for (int i = 0; i < n; i++){
            int k = count(arr[i]);
           // cout << "k : " << k << endl;
            if (res.first < k)
            {
                res.first = k;
                res.second = arr[i];
            }
        }
        int ans = 0;

        for (int i = 0; i < n; i++){
            ans |= (arr[i] ^ res.second);
        }

        cout << res.second << " " << ans << endl;
    }
    return 0;
}