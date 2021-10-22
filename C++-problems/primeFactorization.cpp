#include <bits/stdc++.h>
using namespace std;

// prime factorization : finding all prime factors of a given number
// for ex 20: 2, 2, 5

// [2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17]
//  0, 0, 1, 0, 1, 0, 1, 1,  1,  0,  1,  0,  1,  1,  1,  0

// Position which are marked by 2 * multiplier has smallest prime factor as 2
// So SMF of 4 is 2 , SMF of 6 is 2, SMF of 8 is 2, SMF of 9 is 3 and so on.

int smallestPrimeFactor(int n){
    int arr[100] = {0};

    for (int i = 0; i < 100; i++)
        arr[i] = i;
}

int main(){
    int n;
    cin >> n;


}