#include <bits/stdc++.h>
using namespace std;


// go till last character of string and check last char with preceding char 
// if equal return last char only
// else return prceding char+ last char


string removeDuplicates(string s){
    if(s.length() == 0)
        return "";

    char ch = s[0];
    string ans = removeDuplicates(s.substr(1));

    if(ch == ans[0])
        return ans;
    else
        return ch + ans;
}

int main(){

    string str = removeDuplicates("tuushhar--pathadde");

    cout << str;

    return 0;
}