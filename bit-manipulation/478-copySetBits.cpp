// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution
{
public:
    int setSetBit(int x, int y, int l, int r)
    {
        int position = l;

        int noOfBitsInY = 1 + log2(y);

        while (noOfBitsInY >= position and position <= r)
        {
            if (y & (1 << position - 1))
            {
                x = x | (1 << position - 1); // set bit of x at index = position-1 from left
            }
            position++;
        }

        return x;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int x, y, l, r;
        cin >> x >> y >> l >> r;

        Solution ob;
        cout << ob.setSetBit(x, y, l, r) << "\n";
    }
    return 0;
} // } Driver Code Ends