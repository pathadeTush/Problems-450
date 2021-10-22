#include <bits/stdc++.h>
using namespace std;

// returns total count of setbit in n
int setbitCount(int n){

    int count = 0;
    while(n){
        n = n & (n - 1);
        count++;
    }
    return count;
}

int main(){
    int n;
    cin >> n;

    cout << "Total no. of 1's in binary equivalent of " << n << " : " << setbitCount(n) << endl;

    return 0;
}