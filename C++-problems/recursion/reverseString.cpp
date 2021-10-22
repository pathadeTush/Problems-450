#include <bits/stdc++.h>
using namespace std;

// void reverseString(string str, int index){
//     if(index == str.length())
//         return;
//     reverseString(str, index + 1);
//     cout << str[index];

//     return;
// }

void reverseString(string s){
    if(s.length() == 0)
        return;
    reverseString(s.substr(1));

    cout << s[0];

    return;
}

int main(){
    string str;
    cin >> str;

    reverseString(str);
    return 0;
}