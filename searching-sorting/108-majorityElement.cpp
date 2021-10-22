/*
Given an array A of N elements. Find the majority element in the array. A majority element in an array A of size N is an element that appears more than N/2 times in the array.
 

Example 1:

Input:
N = 3 
A[] = {1,2,3} 
Output:
-1
Explanation:
Since, each element in 
{1,2,3} appears only once so there 
is no majority element.

Example 2:

Input:
N = 5 
A[] = {3,1,3,3,2} 
Output:
3
Explanation:
Since, 3 is present more
than N/2 times, so it is 
the majority element.

Your Task:
The task is to complete the function majorityElement() which returns the majority element in the array. If no majority exists, return -1.
 

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).
 

Constraints:
1 <= N <= 107
0 <= Ai <= 106b
*/

// Function to find majority element in the array
// a: input array
// size: size of input array
int majorityElement(int arr[], int size)
{

    int majorityEle = arr[0];
    int count = 1;

    // get the majority element if it exist as majority
    for (int i = 1; i < size; i++)
    {
        if (arr[i] == majorityEle)
            count++;
        else
            count--;

        if (count == 0)
        {
            majorityEle = arr[i];
            count = 1;
        }
    }

    // now check for the majorityEle if it exist more than size/2 times or not

    int majorityEleCount = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == majorityEle)
            majorityEleCount++;
    }

    if (majorityEleCount > size / 2)
        return majorityEle;

    return -1;
}

/*

Intution:

i = 0         3  1  3  3  2      maj = 3 cnt = 1
i = 1         3  1  3  3  2      maj = 1 cnt = 1    
i = 2         3  1  3  3  2      maj = 3 cnt = 1
i = 3         3  1  3  3  2      maj = 3 cnt = 2
i = 4         3  1  3  3  2      maj = 3 cnt = 1


             3   1   |   3  3  2 
                  cnt=0

in every part except last part, majority element and other element occurs with same freq.
So that they nullify each other. But in last part freq of majority element is more. That's
why we get majority element.
But if no majority element is present then majorityEle will contain another number. So check 
again if the majorityEle is occuring more than n/2 times or not.
*/