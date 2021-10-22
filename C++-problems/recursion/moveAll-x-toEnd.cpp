#include <bits/stdc++.h>
using namespace std;

string moveAllxToLast(string s, char x)
{
    if (s.length() == 0)
        return "";

    char ch = s[0];
    string ans = moveAllxToLast(s.substr(1), x);

    if (ch == x)
        return ans + ch;
    else
        return ch + ans;
}

int main()
{

    string str = moveAllxToLast("rtursrrhrarr", 'r');

    cout << str;

    return 0;
}