/*

Zero Sum Subarrays
Medium Accuracy: 50.41% Submissions: 17187 Points: 4

You are given an array arr[] of size n. Find the total count of sub-arrays having their sum equal to 0.


Example 1:

Input:
n = 6
arr[] = {0,0,5,5,0,0}
Output: 6
Explanation: The 6 subarrays are 
[0], [0], [0], [0], [0,0], and [0,0].


Example 2:

Input:
n = 10
arr[] = {6,-1,-3,4,-2,2,4,6,-12,-7}
Output: 4
Explanation: The 4 subarrays are [-1 -3 4]
[-2 2], [2 4 6 -12], and [-1 -3 4 -2 2]


Your Task:
You don't need to read input or print anything. Complete the function findSubarray() that takes the array arr and its size n as input parameters and returns the total number of sub-arrays with 0 sum. 
 

Expected Time Complexity : O(n)
Expected Auxilliary Space : O(n)
 

Constraints:    
1<= n <= 107
-1010 <= arri <= 1010


*/

class Solution
{
public:
    //Function to count subarrays with sum equal to 0.
    ll findSubarray(vector<ll> arr, int n)
    {

        map<ll, int> mp; // (sum, freq)

        ll count = 0, sum = 0;
        mp[0] = 1;
        for (int i = 0; i < n; i++)
        {
            sum += arr[i];

            if (mp[sum])
                count += mp[sum];

            mp[sum]++; // store the frequency of sum. It may happen that we have got same sum more than 1 time before.
        }

        return count;
    }
};

/*
    0 0 5 5 0 0
mp  0 5 10 
    3 1 3

ans =  6
*/