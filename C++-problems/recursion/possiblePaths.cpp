// Problem: Count the number of paths possible from start
//          point to end point using dice.
// for ex  0, 1, 2   : start 0  and  end 2
// possible path : 0-1 1-2 , 0-2  2 paths

#include <bits/stdc++.h>
using namespace std;

int countPath(int start, int end)
{
    if (start == end)
        return 1;
    if (start > end)
        return 0;

    int count = 0;
    for (int i = 1; i <= 6; i++)
        count += countPath(start + i, end); //  ways of reaching from start to end if i value comes on dice
    // which is = 1 + no. of ways of reaching from start+i to end

    return count;
}

int main()
{

    cout << countPath(1, 3);

    return 0;
}