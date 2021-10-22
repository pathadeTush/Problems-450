// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution
{
public:
    string solve(int arr[], int n)
    {
        string num1 = "";
        string num2 = "";

        // sort array
        sort(arr, arr + n);

        // now store alternate element
        for (int i = n - 1; i >= 0; i--)
        {
            if (i & 1)
                num1 += to_string(arr[i]);
            else
                num2 += to_string(arr[i]);
        }

        //cout << num1 << " "<< num2 << endl;

        // add two string
        string ans = "";
        int n1 = num1.length();
        int n2 = num2.length();
        int i = 0, j = 0;
        int carry = 0;
        while (i < n1 and j < n2)
        {
            int sum = num1[i] - '0' + num2[j] - '0' + carry;
            if (sum > 9)
            {
                sum = sum % 10;
                carry = 1;
            }
            else
                carry = 0;

            ans += to_string(sum);
            i++;
            j++;
        }

        while (i < n1)
        {
            int sum = num1[i] - '0' + carry;
            if (sum > 9)
            {
                sum = sum % 10;
                carry = 1;
            }
            else
                carry = 0;

            ans += to_string(sum);
            i++;
        }
        while (j < n2)
        {
            int sum = num2[j] - '0' + carry;
            if (sum > 9)
            {
                sum = sum % 10;
                carry = 1;
            }
            else
                carry = 0;

            ans += to_string(sum);
            j++;
        }
        if (carry)
            ans += to_string(carry);

        reverse(ans.begin(), ans.end());

        // check for leading zeros
        i = 0;
        while (ans[i] == '0')
            i++;

        return ans.substr(i);
    }
};

// { Driver Code Starts.
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
        {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.solve(arr, n);
        cout << ans << "\n";
    }
    return 0;
} // } Driver Code Ends