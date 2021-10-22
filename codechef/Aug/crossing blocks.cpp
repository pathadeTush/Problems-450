// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     // your code goes here
//     int t;
//     cin >> t;
//     while (t--)
//     {
//         int n;
//         cin >> n;
//         int arr[n], fl = 1;
//         for (int i = 0; i < n; i++)
//         {
//             cin >> arr[i];
//             if (arr[i] > arr[0])
//                 fl = 0;
//         }

//         if (fl == 0)
//             cout << "-1" << endl;
//         else
//         {
//             vector<int> nextGtr(n, -1); // next greater to left

//             stack<int> st;
//             st.push(0);

//             for (int i = 1; i < n; i++)
//             {
//                 while (!st.empty() and arr[i] > arr[st.top()])
//                     st.pop();

//                 if (!st.empty())
//                 {
//                     nextGtr[i] = st.top();
//                     st.push(i);
//                 }
//             }

//             cout << st.size() - 1 << endl;
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
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        int ans = 0, mx = -1;
        for (int i = n - 1; i > 0; i--)
        {
            if (mx < arr[i])
            {
                mx = arr[i];
                ans++;
            }
        }
        if (arr[0] >= mx)
            cout << ans << endl;
        else
            cout << "-1" << endl;
    }
    return 0;
}