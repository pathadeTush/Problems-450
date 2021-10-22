#include <bits/stdc++.h>
using namespace std;


// a num is of power of 2 if it can be represented completely in a power of 2 
// for ex. 1, 2, 4, 8, 16 


// num is power of 2 if  num & (num-1) == 0

// Imp point:  1. n & (n-1)  removes right most setbit(1) from binary equivalent of n
//                              OR
//                n & (n-1) has same bits as n except right most setbit(1).
//
//             2. if we flip the all bit from right most setbit(1) bit of n towards
//                right then we get n-1
//             3. n is nothing but 2's complement of ~(n-1) and n-1 is 1's complement
//                of ~(n-1).

// for ex:  0100 (4) - 0011 (3)
//          0110 (6) - 0101 (5)  


// for n > 0
bool isPowerOf2(int n){
    return !(n & (n - 1));
}

int main(){
    int n;
    cin >> n;

    if(isPowerOf2(n))
        cout << n << " is of power of 2" << endl;
    else
        cout << n << " is not of power of 2" << endl;

    return 0;
}