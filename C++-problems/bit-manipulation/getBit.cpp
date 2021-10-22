#include <bits/stdc++.h>
using namespace std;

// if index is 2 and num is 5
// then 1 << 2 = 0100
// and 0101 & 0100 = 0100

int getBit(int num, int index){
    return (num & (1 << index)) ? 1 : 0;
}

int main(){

    int num, index;
    cin >> num;
    cin >> index;

    cout << "Bit at index " << index << " in binary equivalent of " << num << " is " << getBit(num, index) << endl;

    return 0;
}