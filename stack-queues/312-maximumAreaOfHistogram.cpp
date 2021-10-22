// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], int n)
    {
        if (n == 0)
            return 0;
        if (n == 1)
            return arr[0];

        // find left Boundaries
        vector<int>leftBoundary(n);
        stack<int> lb;
        for (int i = 0; i < n; i++)
        {
            while (!lb.empty() and arr[lb.top()] >= arr[i])
            {
                lb.pop();
            }

            leftBoundary[i] = lb.empty() ? -1 : lb.top();
            lb.push(i);
        }

        // find right Boundaries
        vector <int> rightBoundary(n);
        stack<int> rb;
        for (int i = n - 1; i >= 0; i--)
        {
            while (!rb.empty() and arr[rb.top()] >= arr[i])
            {
                rb.pop();
            }

            rightBoundary[i] = rb.empty() ? n : rb.top();
            rb.push(i);
        }

        // find max area
        long long maxArea = 0;
        for (int i = 0; i < n; i++)
        {
            int width = rightBoundary[i] - leftBoundary[i] - 1;
            long long area = arr[i] * width;

            maxArea = max(maxArea, area);
        }

        return maxArea;
    }
};

// { Driver Code Starts.

int main()
{
    long long t;

    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        long long arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution ob;
        cout << ob.getMaxArea(arr, n) << endl;
    }
    return 0;
}
// } Driver Code Ends