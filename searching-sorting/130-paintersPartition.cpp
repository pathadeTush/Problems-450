/*


The Painter's Partition Problem
Hard Accuracy: 37.8% Submissions: 7579 Points: 8

Dilpreet wants to paint his dog's home that has n boards with different lengths. The length of ith board is given by arr[i] where arr[] is an array of n integers. He hired k painters for this work and each painter takes 1 unit time to paint 1 unit of the board. 

The problem is to find the minimum time to get this job done if all painters start together with the constraint that any painter will only paint continuous boards, say boards numbered {2,3,4} or only board {1} or nothing but not boards {2,4,5}.


Example 1:

Input:
n = 5
k = 3
arr[] = {5,10,30,20,15}
Output: 35
Explanation: The most optimal way will be:
Painter 1 allocation : {5,10}
Painter 2 allocation : {30}
Painter 3 allocation : {20,15}
Job will be done when all painters finish
i.e. at time = max(5+10, 30, 20+15) = 35

Example 2:

Input:
n = 4
k = 2
arr[] = {10,20,30,40}
Output: 60
Explanation: The most optimal way to paint:
Painter 1 allocation : {10,20,30}
Painter 2 allocation : {40}
Job will be complete at time = 60


Your task:
Your task is to complete the function minTime() which takes the integers n and k and the array arr[] as input and returns the minimum time required to paint all partitions.


Expected Time Complexity: O(n log m) , m = sum of all boards' length
Expected Auxiliary Space: O(1)


Constraints:
1 ≤ n ≤ 105
1 ≤ k ≤ 105
1 ≤ arr[i] ≤ 105

*/

class Solution
{
public:
    bool isPossible(int arr[], int n, int painter, long long Time)
    {
        long long timeTaken = 0;
        long long amtPainted = 0;
        int painterRequired = 1;

        for (int i = 0; i < n; i++)
        {

            if (arr[i] > Time)
                return false;

            amtPainted += arr[i];
            timeTaken += arr[i];

            if (timeTaken > Time)
            {
                amtPainted = arr[i];
                timeTaken = arr[i];
                painterRequired++;
            }

            if (painterRequired > painter)
                return false;
        }

        return true;
    }

    long long minTime(int arr[], int n, int k)
    {
        if (n == 0)
            return 0;
        if (k <= 0)
            return -1;

        long long low = -1; // for low, when n = k then minTime = max(arr)
        long long high = 0; // for high, when k = 1 then minTime = sum(arr)

        for (int i = 0; i < n; i++)
        {
            low = max(low, (long long)arr[i]);
            high += arr[i];
        }

        long long ans = -1;
        while (low <= high)
        {
            long long mid = (low + high) >> 1;

            if (isPossible(arr, n, k, mid))
            {
                ans = mid;
                high = mid - 1;
            }
            else
                low = mid + 1;
        }

        return ans;
    }
}