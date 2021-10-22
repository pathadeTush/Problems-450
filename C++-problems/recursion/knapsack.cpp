// Problem: Put n items with given weight and value in a knapsack of capacity W
//          to get the maximum total value in the knapsack.

/* 
W = 50

i            0      1       2
wt[i]       10      20      30
val[i]      100     50      150 

here ans = wt = [10, 30] and val = [100, 150]

we will add particular item if
    
    total value (when it is added) > total value (when it is not added) 

*/

#include <bits/stdc++.h>
using namespace std;

int knapsack(int val[], int wt[], int n, int W, int totalVal)
{
    if (n == 0 || W == 0)
        return totalVal;
    if (W - wt[n - 1] < 0)
        return knapsack(val, wt, n - 1, W, totalVal); // do not add item

    return max(knapsack(val, wt, n - 1, W - wt[n - 1], totalVal + val[n - 1]), knapsack(val, wt, n - 1, W, totalVal));
}

int main()
{
    int wt[] = {10, 20, 30};
    int val[] = {100, 50, 150};
    int W = 50;

    cout << knapsack(val, wt, sizeof(wt) / sizeof(wt[0]), W, 0);

    return 0;
}