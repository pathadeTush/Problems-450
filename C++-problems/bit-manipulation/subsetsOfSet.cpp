#include <bits/stdc++.h>
using namespace std;

// Imp Points: 1 << n gives 2^n

// let set = {a, b}
// possible subset are:
//  consider 0 represent absence of element and 1 represent presence of element
//     {}      = 00   0
//     {b}     = 01   1
//     {a}     = 10   2
//     {a, b}  = 11   3

// O(2^n x n),   n = size of set
void subsets(char set[], int n)
{
    for (int i = 0; i < (1 << n); i++)
    {
        for (int j = 0; j < n; j++)
        {
            // if bit at index j is 1
            if (i & (1 << j))
            {
                cout << set[j] << " ";
            }
        }
        cout << endl;
    }

    return;
}

int main()
{
    char set[] = {'a', 'b', 'c'};

    subsets(set, 3);

    return 0;
}