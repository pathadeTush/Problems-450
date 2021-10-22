#include <bits/stdc++.h>
using namespace std;
//  if string is ab
// do to operation at each step in recursion
// add new char to root and do not add anything to root and add ascii value of char
//
//               ""
//      A        65          ""
// AB  A66 A 65B 6566 65   B 66 ""   // all substrings of AB
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
    substrings(ros, ans + to_string(int(ch)));
    substrings(ros, ans);

    return;
}

int main()
{
    substrings("AB", "");

    return 0;
}