/*

Consider a sample space S consisting of all perfect squares starting from 1, 4, 9 and so on. You are given a number N, you have to output the number of integers less than N in the sample space S.

 

Example 1:

Input :
N = 9
Output:
2
Explanation:
1 and 4 are the only Perfect Squares
less than 9. So, the Output is 2.

Example 2:

Input :
N = 3
Output:
1
Explanation:
1 is the only Perfect Square
less than 3. So, the Output is 1.

 

Your Task:
You don't need to read input or print anything. Your task is to complete the function countSquares() which takes an Integer N as input and returns the answer.

 

Expected Time Complexity: O(sqrt(N))
Expected Auxiliary Space: O(1)

 

Constraints:
1 <= N <= 108



*/

int countSquares(int n)
{
    if (n == 1)
        return 0;
    int count = 1;
    while (count * count < n)
        count++;

    return count - 1;
}




// Better Approach: The idea is to find the largest integer i whose square is less than or equal to the given number. The idea is to use Binary Search to solve the problem. The values of i * i is monotonically increasing, so the problem can be solved using binary search. 


//     Algorithm: 
//         Take care of some base cases, i.e when the given number is 0 or 1.
//         Create some variables, lowerbound l = 0, upperbound r = n, where n is the given number, mid and ans to store the answer.
//         Run a loop until l <= r , the search space vanishes
//         Check if the square of mid (mid = (l + r)/2 ) is less than or equal to n, If yes then search for a larger value in second half of search space, i.e l = mid + 1, update ans = mid
//         Else if the square of mid is more than n then search for a smaller value in first half of search space, i.e r = mid – 1
//         Print the value of answer ( ans)
//     Implementation:

// // A C++ program to find floor(sqrt(x)
// #include <bits/stdc++.h>
// using namespace std;
 
// // Returns floor of square root of x
// int floorSqrt(int x)
// {
//     // Base cases
//     if (x == 0 || x == 1)
//         return x;
 
//     // Do Binary Search for floor(sqrt(x))
//     int start = 1, end = x, ans;
//     while (start <= end) {
//         int mid = (start + end) / 2;
 
//         // If x is a perfect square
//         if (mid * mid == x)
//             return mid;
 
//         // Since we need floor, we update answer when
//         // mid*mid is smaller than x, and move closer to
//         // sqrt(x)
 
//         /*
//            if(mid*mid<=x)
//                    {
//                            start = mid+1;
//                            ans = mid;
//                    }
//             Here basically if we multiply mid with itself so
//            there will be integer overflow which will throw
//            tle for larger input so to overcome this
//            situation we can use long or we can just divide
//             the number by mid which is same as checking
//            mid*mid < x
 
//            */
//         if (mid <= x / mid) {
//             start = mid + 1;
//             ans = mid;
//         }
//         else // If mid*mid is greater than x
//             end = mid - 1;
//     }
//     return ans;
// }
 
// // Driver program
// int main()
// {
//     int x = 11;
//     cout << floorSqrt(x) << endl;
//     return 0;
// }

// Output :

// 3

//     Complexity Analysis: 
//         Time complexity: O(log n). 
//         The time complexity of binary search is O(log n).
//         Space Complexity: O(1). 
//         Constant extra space is needed.

