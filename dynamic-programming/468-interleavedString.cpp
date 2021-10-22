// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution
{
public:
    /*You are required to complete this method */
    bool isInterleave(string A, string B, string C)
    {
        string s1 = "";
        string s2 = "";

        for (int i = 0; i < C.length(); i++)
        {
            if (i & 1)
                s1 += C[i];
            else
                s2 += C[i];
        }

        //cout << s1 << "  " << s2 << endl;

        return ((s1.compare(A) == 0 and s2.compare(B) == 0) or (s1.compare(B) == 0 and s2.compare(A) == 0));
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string a, b, c;
        cin >> a;
        cin >> b;
        cin >> c;
        Solution obj;
        cout << obj.isInterleave(a, b, c) << endl;
    }
    // your code goes here
    return 0;
} // } Driver Code Ends
  
/*

#include<bits/stdc++.h>
using namespace std;

int main(){
    
}

*/