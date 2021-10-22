/*


First non-repeating character in a stream
Medium Accuracy: 51.34% Submissions: 17478 Points: 4

Given an input stream of A of n characters consisting only of lower case alphabets. The task is to find the first non repeating character, each time a character is inserted to the stream. If there is no such character then append '#' to the answer.
 

Example 1:

Input: A = "aabc"
Output: "a#bb"
Explanation: For every character first non
repeating character is as follow-
"a" - first non-repeating character is 'a'
"aa" - no non-repeating character so '#'
"aab" - first non-repeating character is 'b'
"aabc" - first non-repeating character is 'b'

Example 2:

Input: A = "zz"
Output: "z#"
Explanation: For every character first non
repeating character is as follow-
"z" - first non-repeating character is 'z'
"zz" - no non-repeating character so '#'

 

Your Task:
You don't need to read or print anything. Your task is to complete the function FirstNonRepeating() which takes A as input parameter and returns a string after processing the input stream.
 

Expected Time Complexity: O(26 * n)
Expected Space Complexity: O(26)
 

Constraints:
1 <= n <= 105

*/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    string FirstNonRepeating(string s)
    {
        if (s.length() <= 1)
            return s;

        string res = s.substr(0, 1);
        int freq[26] = {0};
        freq[s[0] - 'a']++;
        vector<char> v;
        v.push_back(s[0]);

        for (int i = 1; i < s.length(); i++)
        {
            if (freq[s[i] - 'a'] == 0)
                v.push_back(s[i]);
            freq[s[i] - 'a']++;

            int found = 0;
            for (int j = 0; j < v.size(); j++)
            {
                if (freq[v[j] - 'a'] == 1)
                {
                    res += v[j];
                    found = 1;
                    break;
                }
            }

            if (!found)
            {
                res += "#";
            }
        }

        return res;
    }
};

// { Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        string A;
        cin >> A;
        Solution obj;
        string ans = obj.FirstNonRepeating(A);
        cout << ans << "\n";
    }
    return 0;
} // } Driver Code Ends