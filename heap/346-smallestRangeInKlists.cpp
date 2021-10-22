/*

Smallest range in K lists
Hard Accuracy: 39.25% Submissions: 7415 Points: 8

Given K sorted lists of integers of size N each, find the smallest range that includes at least one element from each of the K lists. If more than one such range's are found, find the first such range found.

Example 1:

Input:
N = 5, K = 3
KSortedArray[][] = {{1 3 5 7 9},
                    {0 2 4 6 8},
                    {2 3 5 7 11}}
Output: 1 2
Explanation: K = 3
A:[1 3 5 7 9]
B:[0 2 4 6 8]
C:[2 3 5 7 11]
Smallest range is formed by number 1
present in first list and 2 is present
in both 2nd and 3rd list.

Example 2:

Input:
N = 4, K = 3
KSortedArray[][] = {{1 2 3 4},
                    {5 6 7 8},
                    {9 10 11 12}}
Output: 4 9

Your Task :

Complete the function findSmallestRange() that receives array , array size n and k as parameters and returns the output range (as a pair in cpp and array of size 2 in java and python)

Expected Time Complexity : O(n * k *log k)
Expected Auxilliary Space  : O(k)

Constraints:
1 <= K,N <= 500
*/

// { Driver Code Starts
/*
logic:
1. keep k pointer pointing to start of each lists
2. store each value of this pointer in minheap and maxheap to get max and min value in log(k) time
3. store min and max value as a pair in ans variable
4. now pop min value from min heap and move that pointer one position ahead and push this value in both heap;
5. update ans every time only if max-min diff is < prev diff

*/

#include <bits/stdc++.h>
using namespace std;
#define N 1000

// } Driver Code Ends
// you are required to complete this function
// function should print the required range

class Solution
{
public:
    pair<int, int> findSmallestRange(int arr[][N], int n, int k)
    {
        priority_queue<pair<int, pair<int, int>>> minHeap;
        priority_queue<pair<int, pair<int, int>>> maxHeap;

        for (int i = 0; i < k; i++)
        {
            minHeap.push({-arr[i][0], {i, 0}});
            maxHeap.push({arr[i][0], {i, 0}});
        }

        pair<int, int> ans = {-minHeap.top().first, maxHeap.top().first};
        int minDiff = ans.second - ans.first;

        int i = minHeap.top().second.first;
        int j = minHeap.top().second.second;
        j++;
        if (j >= n)
            return ans;

        minHeap.pop();
        minHeap.push({-arr[i][j], {i, j}});
        maxHeap.push({arr[i][j], {i, j}});

        //cout << ans.first << " " << ans.second << "  " << i << " " << j << endl;

        while (1)
        {
            int mn = -minHeap.top().first;
            int mx = maxHeap.top().first;
            if (mx - mn < minDiff)
            {
                minDiff = mx - mn;
                ans.first = mn;
                ans.second = mx;
            }
            // cout << ans.first << " " << ans.second << "  " << i << " " << j << endl;
            i = minHeap.top().second.first;
            j = minHeap.top().second.second;
            j++;
            if (j >= n)
                break;

            minHeap.pop();
            minHeap.push({-arr[i][j], {i, j}});
            maxHeap.push({arr[i][j], {i, j}});
        }

        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int arr[N][N];
        pair<int, int> rangee;
        for (int i = 0; i < k; i++)
            for (int j = 0; j < n; j++)
                cin >> arr[i][j];
        Solution obj;
        rangee = obj.findSmallestRange(arr, n, k);
        cout << rangee.first << " " << rangee.second << "\n";
    }
    return 0;
}

// } Driver Code Ends