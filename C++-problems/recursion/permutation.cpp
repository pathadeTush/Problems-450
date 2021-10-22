#include <bits/stdc++.h>
using namespace std;
/*
permutations of a string 
for ex: AB = AB, BA

            per(ab)
    per(a)+b        per(b)+a



*/

void permutation(string s, string ans)
{
    if (s.length() == 0)
    {
        cout << ans << endl;
        return;
    }
    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];
        string ros = s.substr(0, i) + s.substr(i + 1); // exclude ith character from string
        permutation(ros, ans + ch);
    }
    return;
}

/*

            AB
     p(b, a)   p(a, b)
    p("", ba)  p("", ab)  

     ba            ab



*/

int main()
{
    permutation("ABC", "");

    return 0;
}