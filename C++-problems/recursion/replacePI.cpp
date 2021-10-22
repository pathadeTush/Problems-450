#include <bits/stdc++.h>
using namespace std;

// replace 'pi' by 3.14 in a given string using recursion

// void replacePi(string str, int i)
// {
//     if ((i + 1) < str.length() && (str[i] == 'p' && str[i+1] == 'i'))
//     {
//         cout << "3.14";
//         replacePi(str, i + 2);
//     }
//     else if(i < str.length())
//     {
//         cout << str[i];
//         replacePi(str, i + 1);
//     }

//     return;
// }

void replacePi(string str){
    if(str.length() == 0)
        return;
    
    if(str[0] == 'p' && str[1] == 'i')
    {
        cout << "3.14";
        replacePi(str.substr(2));
    }
    else{
        cout << str[0];
        replacePi(str.substr(1));
    }

    return;
}

int main()
{
    string str;
    cin >> str;

    replacePi(str);

    return 0;
}