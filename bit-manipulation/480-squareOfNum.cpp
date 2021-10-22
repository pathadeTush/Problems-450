/*

Square of a num	                     
	  square(n) = 0 if n == 0
	  if n is even 
	     square(n) = 4*square(n/2) 
	  if n is odd
	     square(n) = 4*square(floor(n/2)) + 4*floor(n/2) + 1 

	Examples
	  square(6) = 4*square(3)
	  square(3) = 4*(square(1)) + 4*1 + 1 = 9
	  square(7) = 4*square(3) + 4*3 + 1 = 4*9 + 4*3 + 1 = 49

	How does this work? 

	If n is even, it can be written as
	  n = 2*x 
	  n2 = (2*x)2 = 4*x2
	If n is odd, it can be written as 
	  n = 2*x + 1
	  n2 = (2*x + 1)2 = 4*x2 + 4*x + 1

*/

#include <bits/stdc++.h>
using namespace std;

// int square(int n)
// {
//     if (n == 0)
//         return 0;
//     if (n & 1)
//         return ((square(n / 2) << 2) + ((n/2) << 2) + 1);
//     else
//         return (square(n / 2) << 2);
// }

// int main()
// {
//     int n;
//     cin >> n;

//     cout << "square of n: " << square(n);

//     return 0;
// }

/*

Another Approach:

For a given number `num` we get square of it by multiplying number as `num * num`. 
Now write one of `num` in square `num * num` in terms of power of `2`. Check below examples.

Eg: num = 10, square(num) = 10 * 10 
                          = 10 * (8 + 2) = (10 * 8) + (10 * 2)
    num = 15, square(num) = 15 * 15 
                          = 15 * (8 + 4 + 2 + 1) = (15 * 8) + (15 * 4) + (15 * 2) + (15 * 1)

Multiplication with power of 2's can be done by left shift bitwise operator.


*/

int square(int n)
{
    if (n == 0)
        return 0;
    int ans = 0;
    int num = n;
    int largestPowerOf2 = log2(n);
    while (n and largestPowerOf2 >= 0)
    {
        ans += (num << largestPowerOf2);
        n = n - (1 << largestPowerOf2);
        
        largestPowerOf2 = log2(n);
    }

    return ans;
}

int main()
{
    int n;
    cin >> n;

    cout << "square of n: " << square(n);

    return 0;
}
