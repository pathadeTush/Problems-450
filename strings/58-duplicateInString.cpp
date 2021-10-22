#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    cin >> str;

    int arr[26] = {0};
    for (auto i : str)
        arr[i - 'a']++;

    for (int i = 0; i < 26; i++)
        if (arr[i] > 1)
            printf("%c ", 'a' + i);

    return 0;
}