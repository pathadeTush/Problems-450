/*


logic:

1. first store the (value, index) pair in one vector
2. Now sort it
3. Now try to convert it into original one and count how many swaps are required.

*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    //Function to find the minimum number of swaps required to sort the array.
    int minSwaps(vector<int> &nums)
    {
        vector<pair<int, int>> v; // (value, index)

        for (int i = 0; i < nums.size(); i++)
        {
            v.push_back({nums[i], i});
        }

        sort(v.begin(), v.end());

        int noOfSwaps = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (i == v[i].second)
                continue;
            else
            {
                noOfSwaps++;
                swap(v[i], v[v[i].second]);
                i--;
            }
        }

        return noOfSwaps;
    }
};