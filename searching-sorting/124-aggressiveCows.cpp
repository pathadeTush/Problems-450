/*

AGGRCOW - Aggressive cows
#binary-search
Farmer John has built a new long barn, with N (2 <= N <= 100,000) stalls. The stalls are located along a straight line at positions x1,...,xN (0 <= xi <= 1,000,000,000).

His C (2 <= C <= N) cows don't like this barn layout and become aggressive towards each other once put into a stall. To prevent the cows from hurting each other, FJ wants to assign the cows to the stalls, such that the minimum distance between any two of them is as large as possible. What is the largest minimum distance?
Input
t – the number of test cases, then t test cases follows.
* Line 1: Two space-separated integers: N and C
* Lines 2..N+1: Line i+1 contains an integer stall location, xi
Output
For each test case output one integer: the largest minimum distance.
Example
Input:

1
5 3
1
2
8
4
9
Output:

3
Output details:

FJ can put his 3 cows in the stalls at positions 1, 4 and 8,
resulting in a minimum distance of 3.

*/

/*
Logic:  Apply binary search such that l = arr[0](N cows case) and high = arr[n-1] (2 cows case)
        And check for mid if all cows can be placed with minDist betn them = mid.

        If (canPlaced){
            ans = max(ans, mid);
            l = mid + 1;
        }
        else{
            ans = max(ans, mid);
            h = mid - 1;
        }
*/

// O(nlog(n))
#include <bits/stdc++.h>
using namespace std;

bool isAllCowsCanbePlaced(int stalls[], int n, int cows, int minDistBetn2)
{
    int totalCowsPlaced = 1;
    int prevCowPosn = 0;

    for (int i = 1; i < n; i++)
    {
        if (stalls[i] - stalls[prevCowPosn] >= minDistBetn2)
        {
            prevCowPosn = i;
            totalCowsPlaced++;
        }

        if (totalCowsPlaced == cows)
            return true;
    }
    return false;
}

int largestMinDist(int stalls[], int n, int cows)
{
    // for low: minDistBetn2 can be >= 1
    int low = 1;
    // for high: maximum minDistBetn2 will occure when cows = 2
    int high = stalls[n - 1] - stalls[0];
    int ans = -1;

    while (low <= high)
    {
        int mid = (low + high) >> 1;

        if (isAllCowsCanbePlaced(stalls, n, cows, mid))
        {
            ans = mid;
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    return ans;
}

int main()
{
    int n, cows;
    cin >> n >> cows;
    int stalls[n];

    for (int i = 0; i < n; i++)
        cin >> stalls[i];

    if (cows <= 1)
    {
        cout << 0 << endl;
        return 0;
    }

    sort(stalls, stalls + n);

    cout << largestMinDist(stalls, n, cows) << endl;

    return 0;
}

// 1 2 4 8 9