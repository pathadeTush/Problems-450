
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int sumOfMaxMin(int arr[], int n, int k)
{
    int ans = 0;
    deque<int> decQue, incQue;

    for (int i = 0; i < k; i++)
    {
        // add max and min element with maintaining order
        while (!decQue.empty() and arr[decQue.back()] <= arr[i])
            decQue.pop_back();
        decQue.push_back(i);

        while (!incQue.empty() and arr[incQue.back()] >= arr[i])
            incQue.pop_back();
        incQue.push_back(i);
    }

    for (int i = k; i < n; i++)
    {
        ans += (arr[decQue.front()] + arr[incQue.front()]);

        // remove elements which are not in current window
        while (!decQue.empty() and decQue.front() <= i - k)
            decQue.pop_front();
        while (!incQue.empty() and incQue.front() <= i - k )
            incQue.pop_front();

        // add max and min element with maintaining order
        while (!decQue.empty() and arr[decQue.back()] <= arr[i])
            decQue.pop_back();
        decQue.push_back(i);

        while (!incQue.empty() and arr[incQue.back()] >= arr[i])
            incQue.pop_back();
        incQue.push_back(i);
    }

    ans += (arr[decQue.front()] + arr[incQue.front()]);

    return ans;
}

// Driver program to test above functions
// Driver program to test above functions
int main()
{
    int arr[] = {2, 5, -1, 7, -3, -1, -2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 4;
    cout << sumOfMaxMin(arr, n, k);
    return 0;
}
// } Driver Code Ends
