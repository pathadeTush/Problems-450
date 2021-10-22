#include <bits/stdc++.h>
using namespace std;
#define long long int

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k, s;

        cin >> n >> k >> s;

        int leftSum = s - (n * n), ans = 0;

        for (int i = 2 * n - 1; i > 0;){
            if(leftSum % i == 0  and leftSum / i == k-1)
            {
                ans = i;
                break;
            }
            i = i - 2;
        }

        cout << ans << endl;
    }
}