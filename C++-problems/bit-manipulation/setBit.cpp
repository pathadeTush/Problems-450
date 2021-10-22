#include <bits/stdc++.h>
using namespace std;

// if index is 2 and num is 5
// then 1 << 2 = 0100
// and 0101 || 0100 = 0101

int setBit(int num, int index)
{
    return (num | (1 << index));
}

int main()
{

    int num, index;
    cin >> num;
    cin >> index;

    cout << num << " after seting bit at index " << index << " : "<< setBit(num, index) << endl;

    return 0;
}