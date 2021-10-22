// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<int>> right;
    //Function to insert heap.
    void insertHeap(int &x)
    {
        if (left.size() == 0)
        {
            left.push(x);
            getMedian();
        }
        else if (x > left.top())
        {
            right.push(x);
            balanceHeaps();
            getMedian();
        }
        else
        {
            left.push(x);
            balanceHeaps();
            getMedian();
        }
    }

    //Function to balance heaps.
    void balanceHeaps()
    {
        if ((left.size() - right.size()) == 2)
        {
            right.push(left.top());
            left.pop();
        }
        else if ((right.size() - left.size()) == 1)
        {
            left.push(right.top());
            right.pop();
        }
    }

    //Function to return Median.
    double getMedian()
    {
        if (left.size() - right.size() == 1)
            return (left.top());
        else
            return ((left.top() + right.top()) / 2);
    }
};

// { Driver Code Starts.

int main()
{
    int n, x;
    int t;
    cin >> t;
    while (t--)
    {
        Solution ob;
        cin >> n;
        for (int i = 1; i <= n; ++i)
        {
            cin >> x;
            ob.insertHeap(x);
            cout << floor(ob.getMedian()) << endl;
        }
    }
    return 0;
} // } Driver Code Ends