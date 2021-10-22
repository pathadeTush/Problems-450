#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        long long n;
        scanf("%lld", &n);
        long long arr[n];
        long long duplicates = 0;
        map<long, long> mp;
        for (long long i = 0; i < n; i++){
            scanf("%lld", &arr[i]);
            mp[arr[i]]++;
        }

        // vector<bool> vis(1e6, false);

        // for (long long i = 0; i < n; i++){
        //     if(!vis[arr[i]] and mp[arr[i]] > 1){
        //         duplicates += mp[arr[i]];
        //     }
        //     vis[arr[i]] = true;
        // }
       
        // cout << (n * (n - 1) - (duplicates * (duplicates - 1))) << endl;

        long long ans = 0;
        for (auto it : mp)
        {
            ans += mp[it.first] * (n - mp[it.first]);
        }
        printf("%lld\n", ans);
    }
    return 0;
}