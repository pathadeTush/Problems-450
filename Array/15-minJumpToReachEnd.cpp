/*
          1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9

          | 
jump 1       |  |  |  (jump from 1 to 3)
                5->|  |  |  |  | (discard this ladder as below ladder is larger)
                   8->|  |  |  |  |  |  |  |

(as current ladder vanishes so jump on ladder which we have stored. Here it is of length 8)

jump 2                |  |  |  |  |  |  |  |  (jump from 3 to 8)
    start climbing above ladder and also decrement stairs variable. 
    Meanwhile store larger ladder which we will find at each stairs to the variable ladder.
    
    if we reached at final position in between then return jump from there
           

*/
/* 
class Solution
{
public:
// O(n)
    int minJumps(int a[], int n)
    {

        // we cant moove forward
        if (a[0] == 0)
            return -1;

        int ladder = a[0];     // ladder stores the larger ladder than current ladder (which we are climbing). \
                              It will be used when current ladder finishes.
        int stairs = a[0] - 0; // stairs stores the total stairs for current ladder
        int jump = 1;          // It stores the no. of jumps taken to reached final position.
        // jump will be incremented if current ladder finishes(stairs == 0). Because we will be\
           jumping from current ladder to ladder which we have stored

        for (int i = 1; i < n; i++)
        {
            if (i == n - 1)
                return jump;

            ladder = max(ladder, a[i] + i);
            stairs--;

            if (stairs == 0)
            {
                stairs = ladder - i;
                jump++;
            }

            // if we cant move forward. (This case appears if we reached at position where a[i) = 0
            if (stairs == 0)
                return -1;
        }
        return jump;
    }
};
 */

// O(n^2) --> DP approach

// logic: minStep for position i = minStep for (i-1) + 1;

#include <bits/stdc++.h>
using namespace std;

// 1 3 0 5 4  --> arr
// 0 1 2 2 2  --> dp  (min Jump)
// ans = 2

// 1 0 0 5 4  --> arr
// 0 1 m m m  --> dp  (min Jump)
// ans = -1

// iterative soln
/* int getMinJump(int arr[], int n){
    int dp[n]; // it will store min jump to reach at each position from start (oth position)

    for (int i = 0; i < n; i++)
        dp[i] = INT_MAX;

    dp[0] = 0; // No jump to reach at start position

    for (int i = 1; i < n; i++){
        for (int j = 0; j < i; j++){
            if(dp[j] != INT_MAX && arr[j] + j >= i) // we can reached at j and we can reached from j to i
            {
                dp[i] = min(dp[i], dp[j] + 1); // update min jump for i
            }
        }
    }

    if (dp[n - 1] == INT_MAX)
        return -1;
    else
        return dp[n-1];
}



int main(){
    int n;
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Min Jump: " << getMinJump(arr, n);

    return 0;
}


 */

// 1 3 0 5 4  --> arr
// 0 1 2 2 2  --> dp  (min Jump)
// ans = 2

// recursive soln
// O(n^2)
int getMinJump(int arr[], int n, int currentIndex, int jump)
{
    if (currentIndex >= n)
        return jump;

    int res = INT_MAX;
    for (int i = 1; i <= arr[currentIndex]; i++)
        res = min(res, getMinJump(arr, n, currentIndex + i, jump + 1));

    return (res == INT_MAX) ? -1 : res;
}

int main()
{
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Min Jump: " << getMinJump(arr, n, 1, 0);

    return 0;
}
