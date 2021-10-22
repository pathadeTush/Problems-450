#include <bits/stdc++.h>
using namespace std;

// Condition: No duplicates are present in an array

// vector<vector<int>> ans;

// void permutation(vector<int> &arr, int idx)
// {
//     if (idx == arr.size())
//     {
//         ans.push_back(arr);
//         return;
//     }
//     for (int i = idx; i < arr.size(); i++)
//     {
//         swap(arr[i], arr[idx]);
//         permutation(arr, idx + 1);
//         swap(arr[i], arr[idx]);
//     }
//     return;
// }

// int main()
// {
//     int n, k;
//     cin >> n;
//     vector<int> arr;
//     for (int i = 0; i < n; i++)
//     {
//         cin >> k;
//         arr.push_back(k);
//     }

//     permutation(arr, 0);

//     for (auto v : ans)
//     {
//         for (auto i : v)
//             cout << i;
//         cout << endl;
//     }

//     return 0;
// }

// using STL

// O(n!)

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (auto &i : arr)
        cin >> i;

    sort(arr.begin(), arr.end());

    vector<vector<int>> ans;

    do
    {
        ans.push_back(arr);
    } while (next_permutation(arr.begin(), arr.end()));

    for (auto v : ans)
    {
        for (auto i : v)
            cout << i;
        cout << endl;
    }

    return 0;
}