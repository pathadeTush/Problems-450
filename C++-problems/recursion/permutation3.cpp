#include <bits/stdc++.h>
using namespace std;

// Duplicates element can be in an array

vector<vector<int>> ans;

void permutation(vector<int> &arr, int idx)
{
    if (idx == arr.size())
    {
        ans.push_back(arr);
        return;
    }
    for (int i = idx; i < arr.size(); i++)
    {
        if (i != idx and arr[i] == arr[idx])
            continue;
        swap(arr[i], arr[idx]);
        permutation(arr, idx + 1);
    }
    return;
}

int main()
{
    int n, k;
    cin >> n;
    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        cin >> k;
        arr.push_back(k);
    }
    // sort(arr.begin(), arr.end());
    permutation(arr, 0);

    for (auto v : ans)
    {
        for (auto i : v)
            cout << i << " ";
        cout << endl;
    }

    return 0;
}
