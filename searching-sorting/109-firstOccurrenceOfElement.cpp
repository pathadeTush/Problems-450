/*

earching in an array where adjacent differ by at most k
Easy Accuracy: 67.03% Submissions: 1738 Points: 2

A step array is an array of integer where each element has a difference of at most k with its neighbor. Given a key x, we need to find the index value of k if multiple elements exist, return the first occurrence of the key.


Example 1:

â€‹Input : arr[ ] = {4, 5, 6, 7, 6}, K = 1 
        and X = 6
Output : 2
Explanation:
In an array arr 6 is present at index 2.
So, return 2.


â€‹Example 2:

Input : arr[ ] = {20 40 50}, K = 20 
        and X = 70
Output :  -1 

 

Your Task:
This is a function problem. The input is already taken care of by the driver code. You only need to complete the function search() that takes an array (arr), sizeOfArray (n), an integer value X, another integer value K, and return an integer displaying the index of the element X in the array arr. If the element is not present in the array return -1. The driver code takes care of the printing.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).

 

Constraints:
1 ≤ N ≤ 105
1 ≤ K ≤ 102
1 ≤ arr[i], X ≤ 105

*/

// x is the element to be searched in arr[0..n-1]
// such that all elements differ by at-most k.
int search(int arr[], int n, int x, int k)
{
    for (int i = 0; i < n; i++)
        if (arr[i] == x)
            return i;

    return -1;
}

/*

A Simple Approach is to traverse the given array one by one and compare every element with the given element ‘x’. If matches, then return index.
The above solution can be Optimized using the fact that the difference between all adjacent elements is at most k. The idea is to start comparing from the leftmost element and find the difference between the current array element and x. Let this difference be ‘diff’. From the given property of the array, we always know that x must be at least ‘diff/k’ away, so instead of searching one by one, we jump ‘diff/k’. 
Below is the implementation of the above idea.
 

// C++ program to search an element in an array
// where difference between adjacent elements is atmost k
#include<bits/stdc++.h>
using namespace std;
 
// x is the element to be searched in arr[0..n-1]
// such that all elements differ by at-most k.
int search(int arr[], int n, int x, int k)
{
    // Traverse the given array starting from
    // leftmost element
    int i = 0;
    while (i < n)
    {
        // If x is found at index i
        if (arr[i] == x)
            return i;
 
        // Jump the difference between current
        // array element and x divided by k
        // We use max here to make sure that i
        // moves at-least one step ahead.
        i = i + max(1, abs(arr[i]-x)/k);
    }
 
    cout << "number is not present!";
    return -1;
}
 
// Driver program to test above function
int main()
{
    int arr[] = {2, 4, 5, 7, 7, 6};
    int x = 6;
    int k = 2;
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "Element " << x  << " is present at index "
         << search(arr, n, x, k);
    return 0;
}
Output: 

Element 6 is present at index 5

*/