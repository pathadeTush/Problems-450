#include <bits/stdc++.h>
using namespace std;

// if index is 2 and num is 5
// then ! (1 << 2) = 1011
// and 0101 & 1011 = 0001

int clearBit(int num, int index)
{
    return (num & ~(1 << index));
}

int main()
{

    int num, index;
    cin >> num;
    cin >> index;

    cout << num << " after clearing bit at index " << index << " : " << clearBit(num, index) << endl;

    return 0;
}