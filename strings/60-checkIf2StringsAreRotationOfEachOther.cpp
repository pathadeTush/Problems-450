#include <bits/stdc++.h>
using namespace std;


bool isSameOnRatation(string s1, string s2){
    if(s1.length() != s2.length())
        return false;
    if(s1.length() == 0)
        return true;

// if s1 can be obtained from s2 then s2 must be substring of string which concatenation of s1 with itself.
    string concatenatedStr = s1 + s1;

    int len = s2.length();
    int prefixLength = 0;

    for (int i = 0; i < 2 * len; i++){
        if(prefixLength == len)
            return true;
        if (s2[prefixLength] == concatenatedStr[i])
            prefixLength++;
        else
            prefixLength = 0;
    }
    return false;
}

int main()
{
    string str1, str2;
    cin >> str1;
    cin >> str2;

    cout << isSameOnRatation(str1, str2);

    return 0;
}