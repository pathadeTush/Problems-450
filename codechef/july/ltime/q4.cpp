// #include <iostream>
// using namespace std;

// int main()
// {
//     // your code goes here
//     int t;
//     scanf("%d", &t);
//     while(t--){
//         long long n;
//         scanf("%lld", &n);
//         long long a[n], b[n];

//         for (long long i = 0; i < n;i++)
//             scanf("%lld", &a[i]);

//         for (long long i = 0; i < n; i++)
//             scanf("%lld", &b[i]);

//         long long mn = 4*n + 1;
//         for (long long i = 0; i < n; i++){
//             mn = min((a[0] + b[i]) % n, mn);
//         }
//     }

//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
int main()
{

    int t;
    cin >> t;

    while (t--)

    {
        int n;
        cin >> n;
        int mi = 4 * n + 1;

        vector<int>a, b, c;

        for (int i = 0; i < n; i++)
        {
            int num;
            cin >> num;

            a.push_back(num);
        }

        for (int i = 0; i < n; i++)

        {

            int num;
            cin >> num;

            b.push_back(num);
        }

        vector<int> v;

        for (int i = 0; i < n; i++)
            mi = min(mi, (a[0] + b[i]) % n);

        for (int i = 0; i < n; i++){
            if ((a[0] + b[i]) % n == mi)
                v.push_back(i);
        }

        if (v.size() == 1)
        {
             rotate(b.begin(), b.begin() + v[0], b.end());

            for (int i = 0; i < n; i++)
            {
                int k = (a[i] + b[i]) % n;
                c.push_back(k);
            }
        }
        else
        {
            int index = 0;

            int l = 0;
            int i = 0;
            int b1, b2;

            int mod1 = (a[0] + b[v[0]]) % n;

            int mod2 = (a[0] + b[v[1]]) % n;

            while (i < n - 1 && mod1 == mod2)

            {
                b1 = (v[0] + 1) % n;
                b2 = (v[1] + 1) % n;
                i++;
                mod1 = (a[i] + b[b1]) % n;
                mod2 = (a[i] + b[b2]) % n;
            }
            if (mod1 < mod2)
                index = v[0];
            else
                index = v[1];

            rotate(b.begin(), b.begin() + index, b.end());

            for (int i = 0; i < n; i++)
            {
                int k = (a[i] + b[i]) % n;
                c.push_back(k);
            }
        }

        for (int i = 0; i < n; i++)
            cout << c[i] << " ";
    }
}