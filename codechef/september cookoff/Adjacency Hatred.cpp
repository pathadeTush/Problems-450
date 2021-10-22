#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    // your code goes here
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        vector<int> even;
        vector<int> odd;
        int odd_count = 0, even_count = 0;

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            if (arr[i] % 2 == 0)
            {
                even_count++;
                even.push_back(arr[i]);
            }
            else
            {
                odd_count++;
                odd.push_back(arr[i]);
            }
        }

        if (even_count == 0 or odd_count == 0)
            cout << "-1\n";
        else{
            while(even_count--)
                cout << even[even_count] << " ";
            while(odd_count--)
                cout << odd[odd_count] << " ";
            cout << "\n";
        }

    }
    return 0;
}
