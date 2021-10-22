/*


Next Greater Element
Medium Accuracy: 48.92% Submissions: 46019 Points: 4

Given an array arr[ ] of size N having distinct elements, the task is to find the next greater element for each element of the array in order of their appearance in the array.
Next greater element of an element in the array is the nearest element on the right which is greater than the current element.
If there does not exist next greater of current element, then next greater element for current element is -1. For example, next greater of the last element is always -1.

Example 1:

Input: 
N = 4, arr[] = [1 3 2 4]
Output:
3 4 4 -1
Explanation:
In the array, the next larger element 
to 1 is 3 , 3 is 4 , 2 is 4 and for 4 ? 
since it doesn't exist, it is -1.

Example 2:

Input: 
N = 5, arr[] [6 8 0 1 3]
Output:
8 -1 1 3 -1
Explanation:
In the array, the next larger element to 
6 is 8, for 8 there is no larger elements 
hence it is -1, for 0 it is 1 , for 1 it 
is 3 and then for 3 there is no larger 
element on right and hence -1.

Your Task:
This is a function problem. You only need to complete the function nextLargerElement() that takes list of integers arr[ ] and N as input parameters and returns list of integers of length N denoting the next greater elements for all the corresponding elements in the input array.

Expected Time Complexity : O(N)
Expected Auxilliary Space : O(N)

Constraints:
1 ≤ N ≤ 106
1 ≤ Ai ≤ 1018

*/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    /*
    Logic:
    1. Push the start element to the stack
    2. i. Now apply loop from 1 to n-1
       ii. For each element do the follwing
            if(top > arr[i]) the =n push it
            else pop all element which are smaller than arr[i] and mark their next greator value as arr[i]
            
    3. After finishing loop. pop all stack element and marks their next greator as -1
    */

    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n)
    {
        stack<pair<long long, int>> st;
        vector<long long> res(n);

        st.push({arr[0], 0});

        for (int i = 1; i < n; i++)
        {
            if (st.top().first > arr[i])
                st.push({arr[i], i});
            else
            {
                while (!st.empty() and st.top().first < arr[i])
                {
                    res[st.top().second] = arr[i];
                    st.pop();
                }
                st.push({arr[i], i});
            }
        }
        while (!st.empty())
        {
            res[st.top().second] = -1;
            st.pop();
        }

        return res;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int n;
        cin >> n;
        vector<long long> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        Solution obj;
        vector<long long> res = obj.nextLargerElement(arr, n);
        for (long long i : res)
            cout << i << " ";
        cout << endl;
    }
    return 0;
} // } Driver Code Ends