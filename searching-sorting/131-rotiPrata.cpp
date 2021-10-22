/*

PRATA - Roti Prata
no tags 

IEEE is having its AGM next week and the president wants to serve cheese prata after the meeting. The subcommittee members are asked to go to food connection and get P(P<=1000) pratas packed for the function. The stall has L cooks(L<=50) and each cook has a rank R(1<=R<=8). A cook with a rank R can cook 1 prata in the first R minutes 1 more prata in the next 2R minutes, 1 more prata in 3R minutes and so on(he can only cook a complete prata) ( For example if a cook is ranked 2.. he will cook one prata in 2 minutes one more prata in the next 4 mins an one more in the next 6 minutes hence in total 12 minutes he cooks 3 pratas in 13 minutes also he can cook only 3 pratas as he does not have enough time for the 4th prata). The webmaster wants to know the minimum time to get the order done. Please write a program to help him out.

 
Input

The first line tells the number of test cases. Each test case consist of 2 lines. In the first line of the test case we have P the number of prata ordered. In the next line the first integer denotes the number of cooks L and L integers follow in the same line each denoting the rank of a cook.
Output

Print an integer which tells the number of minutes needed to get the order done.

 
Example

Input:

3
10
4 1 2 3 4
8
1 1
8
8 1 1 1 1 1 1 1 1

Output:
12
36
1

*/

#include <bits/stdc++.h>
using namespace std;

bool isOrderComplete(int rank[], int totalCooks, int order, int Time)
{
    int totalPrataPossible = 0;

    for (int i = 0; i < totalCooks; i++)
    {

        int t = rank[i];
        int j = 2;
        while (t <= Time)
        {
            totalPrataPossible++;
            t += j * rank[i];
            j++;
        }

        if (totalPrataPossible >= order)
            return true;
    }

    return false;
}

int minTime(int rank[], int totalCooks, int order)
{
    int low = 0;
    int high = 1e8;

    int ans = -1;
    while (low <= high)
    {
        int mid = (low + high) >> 1;

        if (isOrderComplete(rank, totalCooks, order, mid))
        {
            ans = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }

    return ans;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int order, totalCooks;
        cin >> order >> totalCooks;

        int *rank = new int[totalCooks];

        for (int i = 0; i < totalCooks; i++)
            cin >> rank[i];

        cout << minTime(rank, totalCooks, order) << endl;

        delete[] rank;
    }

    return 0;
}

/*

time = n/2[2a + (n-1)d]

time = n / 2 [2*rank[i] + (n-1)*rank[i]]

n = (-1 +/- D) / 2;

D^2 = (1 - (8Time/rank[i]));  
      
*/