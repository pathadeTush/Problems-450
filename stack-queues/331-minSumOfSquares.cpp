/*


Game with String
Easy Accuracy: 69.39% Submissions: 4380 Points: 2

Given a string s of lowercase alphabets and a number k, the task is to print the minimum value of the string after removal of ‘k’ characters. The value of a string is defined as the sum of squares of the count of each distinct character.
 

Example 1:

Input: s = abccc, k = 1
Output: 6
Explaination:
We remove c to get the value as 12 + 12 + 22

 

Example 2:

Input: s = aabcbcbcabcc, k = 3
Output: 27
Explaination: We remove two 'c' and one 'b'. 
Now we get the value as 32 + 32 + 32.


Your Task:
You do not need to read input or print anything. Your task is to complete the function minValue() which takes s and k as input parameters and returns the minimum possible required value.

 

Expected Time Complexity: O(N*logN)  where N is the length of string
Expected Auxiliary Space: O(N)

 

Constraints:
1 ≤ k ≤ |string length| ≤ 100

*/

// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
  int minValue(string s, int k)
  {

    map<char, int> mp;

    for (int i = 0; i < s.length(); i++)
      mp[s[i]]++;

    // max heap
    priority_queue<pair<int, char>> pq;

    for (auto i : mp)
      pq.push({i.second, i.first});

    for (int i = 0; i < k; i++)
    {
      pair<int, char> temp = pq.top();
      pq.pop();
      temp.first--;
      pq.push(temp);
    }

    int sum = 0;

    while (!pq.empty())
    {
      sum += (pq.top().first * pq.top().first);
      pq.pop();
    }

    return sum;
  }
};

// { Driver Code Starts.

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    string s;
    int k;
    cin >> s >> k;

    Solution ob;
    cout << ob.minValue(s, k) << "\n";
  }
  return 0;
} // } Driver Code Ends