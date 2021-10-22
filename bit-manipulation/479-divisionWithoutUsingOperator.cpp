#include <bits/stdc++.h>
using namespace std;

// /*

// This approach is only works if divisor is of power of 2
// intution:

//     quotient| remainder
// 7/2  = 1 1 | 1
//        --------
//          1 | 0

// it same for all numbers
// */

// int Div(int a, int b){
//     int noOfBitsInB = 1+log2(b);

//     return a >> (noOfBitsInB - 1);
// }

/*

multiply divisor by 2 times till it is less than dividend. then add 2 * (how many times multiplied) to the quotient. subtract divisor * 2 (i-1) from dividend. repeat the same procedure until divisor <= dividend
*/
int Div(int a, int b)
{
    if (b == 0)
        return -1;
    int quotient = 0;
    while (a >= b)
    {
        int i = 0;
        while ((b << i) <= a)
            i++;

        quotient += (1 << (i - 1));
        a = a - (b << (i - 1));
    }
    return quotient;
}

int main()
{
    int a, b;
    cin >> a;
    cin >> b;

    cout << a << " / " << b << " : " << Div(a, b);

    return 0;
}
