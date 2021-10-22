#include <bits/stdc++.h>
using namespace std;

// void substrings(string s, int num){
//     if(pow(2, s.length()) == num){
//         return;
//     }
//     substrings(s, num + 1);

//     for (int i = 0; i < s.length(); i++)
//         if((num & (1 << i)) == (1 << i)) // if bit 1 at position i from right in num
//             cout << s[i];

//     cout << endl;

//     return;
// }

//  if string is ab
// do to operation at each step in recursion
// add new char to root and do not add anything to root
//
//         ""
//      a      ""
//   ab   a  b    ""  // all substrings of ab

// void substrings(string s, int i, string ans)
// {
//     if (i == s.length())
//     {
//         cout << ans << endl;
//         return;
//     }

//     substrings(s, i + 1, ans + s[i]);
//     substrings(s, i + 1, ans);

//     return;
// }

void substrings(string s, string ans)
{
    if (s.length() == 0)
    {
        cout << ans << endl;
        return;
    }

    char ch = s[0];
    string ros = s.substr(1);

    substrings(ros, ans + ch);
    substrings(ros, ans);

    return;
}

int main()
{
    substrings("abc", "");

    return 0;
}