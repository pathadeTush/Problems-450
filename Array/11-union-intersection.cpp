#include <bits/stdc++.h>
using namespace std;



void doUnion(int a[], int n, int b[], int m)
{
    map<int, bool> mp; // value, (true/false)
    // true: value considered/ taken in union
    // false: value not considered

    int countOfIntersection = 0;

    for (int i = 0; i < n; i++)
        mp[a[i]] = true;
    for (int i = 0; i < m; i++)
        if (!mp[b[i]])
            mp[b[i]] = true;
        else
            countOfIntersection++;

    cout << "no. of elements in union: " << mp.size() << endl;
    cout << "no. of element in intersection: " << countOfIntersection;

    return;
}