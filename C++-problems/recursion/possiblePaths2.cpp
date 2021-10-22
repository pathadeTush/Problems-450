// Problem: Count all possible paths from position i, j to n-1, n-1 in a 2D matrix
//          provided you can move either right or down (n = total row or total column)

#include <bits/stdc++.h>
using namespace std;

int countPath(int n, int i, int j){
    if(i == n-1 && j == n-1)
        return 1;
    if(i > n-1 || j > n-1)
        return 0;

    return countPath(n, i + 1, j) + countPath(n, i, j + 1);
}

int main(){

    cout << countPath(3, 0, 0);
    return 0;
}

/* 
1 2 3
4 5 6
7 8 9


1-4-5-8-9
1-4-5-6-9
1-4-7-8-9
1-2-3-6-9
1-2-5-6-9
1-2-5-8-9
 */ 