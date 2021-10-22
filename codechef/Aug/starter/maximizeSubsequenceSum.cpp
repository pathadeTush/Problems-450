// #include <bits/stdc++.h>
// using namespace std;

// int maxSum(vector<int> v, int sum, int k, int n, vector<vector<int>> &dp)
// {
//     if (k == 0)
//         return sum;
//     if (n == 0)
//         return -1;

//     if (dp[n][k] != -1)
//         return dp[n][k];

//     //cout << " dffd: " << v[n - 1] << endl;
//     int include = maxSum(v, sum + v[n - 1], k - 1, n - 1, dp);
//     int exclude = maxSum(v, sum, k, n - 1, dp);

//     //cout << include << "  " << exclude << endl;

//     return dp[n][k] = max(include, exclude);
// }

// int main()
// {
//     int t;
//     cin >> t;

//     while (t--)
//     {
//         int n, k;
//         cin >> n >> k;

//         int arr[n];

//         vector<int> v;
//         int sum = 0, negSum = 0;

//         for (int i = 0; i < n; i++)
//         {
//             cin >> arr[i];
//             if (arr[i] < 0)
//             {
//                 v.push_back(abs(arr[i]));
//                 negSum += abs(arr[i]);
//             }
//             sum += abs(arr[i]);
//         }
//          if (v.size() <= k)
//             cout << sum << endl;
//         else
//         {
//             vector<vector<int>> dp(v.size() + 1, vector<int>(k + 1, -1));

//             int mxNegSum = maxSum(v, 0, k, v.size(), dp);
//             //cout << "mxnegSum: " << mxNegSum << endl;
//             sum = sum - (negSum - mxNegSum);
//             cout << sum << endl;
//         }
//     }
// }

#include <bits/stdc++.h>
using namespace std;

bool comp(int a, int b)
{
    return (abs(a) < abs(b));
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, k;
        cin >> n >> k;

        int arr[n];

        for (int i = 0; i < n; i++)
            cin >> arr[i];

        sort(arr, arr + n, comp);

        int sum = 0;
        for (int i = n - 1; i >= 0; i--)
        {
           // cout << "sum " << sum << '\n';
            if (arr[i] < 0 and k > 0)
            {
                k--;
                sum += abs(arr[i]);
            }
            else if(arr[i] > 0)
            sum += arr[i];
        }
        if (sum < 0)
            cout << "0" << endl;
        else
            cout << sum << endl;
    }
    return 0;
}