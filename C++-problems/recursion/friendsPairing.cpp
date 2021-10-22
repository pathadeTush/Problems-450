// Problem: Find the number of ways in which n friends can remain single or can be paired up.

#include <bits/stdc++.h>
using namespace std;


int friendsPairing(int n){
    if(n == 0 || n == 1 || n == 2)
        return n;

    return friendsPairing(n - 1) + (n - 1) * friendsPairing(n - 2);
    //       to leave nth member single OR    pair it 
}

int main(){

    cout << friendsPairing(4);

    return 0;
}