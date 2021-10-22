// Problem: Given "2xn" board and tiles of size "2x1", count number of
//          ways to tile the given board using these tiles

/* 
_ _ _ _            1
_ _ _ _            1

1. if tile is added vertically then size of board reduced to 2 x n-1 as one column is occupied

2. if tile is added horizontally then size of board reduced to 2 x n-2 as two column are occupied

 */



#include <bits/stdc++.h>
using namespace std;

int tilingWays(int n){
    if(n == 0 || n == 1)
        return 1;

    return tilingWays(n - 1) + tilingWays(n - 2);
}

int main(){

    cout << tilingWays(3);

    return 0;
}