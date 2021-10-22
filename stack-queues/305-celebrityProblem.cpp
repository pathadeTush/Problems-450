// { Driver Code Starts
//Initial template for C++

/*


The Celebrity Problem
Medium Accuracy: 39.46% Submissions: 72325 Points: 4

A celebrity is a person who is known to all but does not know anyone at a party. If you go to a party of N people, find if there is a celebrity in the party or not.
A square NxN matrix M[][] is used to represent people at the party such that if an element of row i and column j  is set to 1 it means ith person knows jth person. Here M[i][i] will always be 0.
Note: Follow 0 based indexing.
 

Example 1:

Input:
N = 3
M[][] = {{0 1 0},
         {0 0 0}, 
         {0 1 0}}
Output: 1
Explanation: 0th and 2nd person both
know 1. Therefore, 1 is the celebrity. 


Example 2:

Input:
N = 2
M[][] = {{0 1},
         {1 0}}
Output: -1
Explanation: The two people at the party both
know each other. None of them is a celebrity.


Your Task:
You don't need to read input or print anything. Complete the function celebrity() which takes the matrix M and its size N as input parameters and returns the index of the celebrity. If no such celebrity is present, return -1.


Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)


Constraints:
2 <= N <= 3000
0 <= M[][] <= 1

*/

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution
{
public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int>> &M, int n)
    {
        stack<int> st;
        for (int i = 0; i < n; i++)
            st.push(i);

        while (st.size() > 1)
        {
            int i = st.top();
            st.pop();
            int j = st.top();
            st.pop();

            if (M[i][j] == 1) // if i knows j implies i can't be celebrity
                st.push(j);
            else
                st.push(i); // if i doesn't know j implies j can't be celebrity
        }

        int celebrity = st.top();
        st.pop();

        for (int i = 0; i < n; i++)
        {
            if (i != celebrity)
            {
                // if celebrity knows i  OR  i doesn't know celebrity
                if (M[celebrity][i] or !M[i][celebrity])
                    return -1;
            }
        }

        return celebrity;
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
        vector<vector<int>> M(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> M[i][j];
            }
        }
        Solution ob;
        cout << ob.celebrity(M, n) << endl;
    }
}
// } Driver Code Ends