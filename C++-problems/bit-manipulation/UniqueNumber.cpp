#include <bits/stdc++.h>
using namespace std;

// // Problem: Find a unique num in an array where all numbers except one,
// //          are present twice

int main(){
    int arr[] = {2, 4, 6, 3, 4, 6, 2, 2, 4, 6};
    int unique = arr[0];

    for (int i = 1; i < sizeof(arr) / sizeof(arr[0]); i++)
        unique ^= arr[i];

    cout << unique;

    return 0;
}

// Problem: Find a two unique num in an array where all numbers except two,
//          are present twice

// int main()
// {
//     int arr[] = {2, 4, 6, 3, 4, 6, 2, 5};
//     int unique = arr[0];

//     for (int i = 1; i < sizeof(arr) / sizeof(arr[0]); i++)
//         unique ^= arr[i];

//     int position = 0;

//     // to get position of right most 1 in unique
//     while ((unique & (1 << position)) != (1 << position))
//         position++;

//     int num1 = unique;

//     for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
//     // element which are unique will come 2 times and will get xor to 0 hence we will get one of two unique number here.
//         if ((arr[i] & (1 << position)) == (1 << position))
//             num1 ^= arr[i];

//     int num2 = unique ^ num1;

//     cout << num1 << " " << num2;

//     return 0;
// }

// 0101
// 0011
// 0110
// XY'+X'Y

// 1 bit in ans implies there must be 1 in exactly one of two number at that position.
// xor result with numbers which have 1 at position 2 from right. By doing that we get our one ans.
