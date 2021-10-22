/*
K-th Largest Sum Contiguous Subarray

    Difficulty Level : Medium
    Last Updated : 12 May, 2021

Given an array of integers. Write a program to find the K-th largest sum of contiguous subarray within the array of numbers which has negative and positive numbers.

Examples: 

Input: a[] = {20, -5, -1} 
         k = 3
Output: 14
Explanation: All sum of contiguous 
subarrays are (20, 15, 14, -5, -6, -1) 
so the 3rd largest sum is 14.

Input: a[] = {10, -10, 20, -40} 
         k = 6
Output: -10 
Explanation: The 6th largest sum among 
sum of all contiguous subarrays is -10.
*/

/*
1 2 3

1
1 2
1 2 3
2
2 3
3


subarr count = n*(n-1) / 2
*/

#include <bits/stdc++.h>
using namespace std;

int kthLargestSumSubarr(int arr[], int n, int k)
{
    if (n == 0)
        return -1;

    priority_queue<int> pq; // we want maximum here so use min heap

    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += arr[j];
            //  cout << sum << endl;
            pq.push(-sum); // push with negative sign to implement it as min heap
            if (pq.size() > k)
                pq.pop();
        }
    }

    return -pq.top();
}

int main()
{
    int n, k;
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << kthLargestSumSubarr(arr, n, k) << endl;

    return 0;
}