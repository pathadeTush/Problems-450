#include <bits/stdc++.h>
using namespace std;
/*

A Simple Solution is to consider every index ‘i’ and do the following 

Max profit with at most two transactions =
       MAX {max profit with one transaction and subarray price[0..i] +
            max profit with one transaction and subarray price[i+1..n-1]  }
i varies from 0 to n-1.

Maximum possible using one transaction can be calculated using the following O(n) algorithm 
The maximum difference between two elements such that the larger element appears after the smaller number. see Q-22

Since we have to perfrom above operation for each ith elemenet. Hence the time complexity of the above simple solution is O(n2).



Effiecient approach.
 1. calculate maxProfit for each subarr [0 to i] and store it an array maxProfit.
    such that cost price is minimum and selling price is maximum and cost price occurs
    left/ prior to selling price

 Now for each ith price we have max profit from [0 to i] stored in maxProfit[i]

 2. Now we have to find max profit for [i to n-1] 
    such that cost price is minimum and selling price is maximum and cost price occurs
    left/ prior to selling price. But this time we will iterate from right to left.
    This time we will meet selling price first and then cost price. Update maxProfit
    for each i 
*/

int maxProfit(int prices[], int n){
    int profit[n]; // profit array to store the max profit after 1st transaction for [0 to i]
    for (int i = 0; i < n; i++)
        profit[i] = 0;

    int minCostPrice = prices[0];
    for (int i = 1; i < n; i++){
        minCostPrice = min(minCostPrice, prices[i]);
        profit[i] = max(profit[i-1], prices[i] - minCostPrice);
    }

    int maxSellPrice = INT_MIN;
    int maxProfit = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        maxSellPrice = max(maxSellPrice, prices[i]);
        maxProfit = max(maxProfit, maxSellPrice - prices[i]);

        // profit[i] + maxProfit =  profit of 1st transaction + profit of second transaction
        profit[i] = max(profit[i], profit[i] + maxProfit);
    }

    maxProfit = 0;
    for (int i = 0; i < n; i++)
        maxProfit = max(maxProfit, profit[i]);

    return maxProfit;
}

int main(){
    int n;
    cin >> n;

    int prices[n];
    for (int i = 0; i < n; i++)
        cin >> prices[i];

    cout << maxProfit(prices, n);

    return 0;
}