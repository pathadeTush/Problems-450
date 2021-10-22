// Method 3 (Use elements as Index and mark the visited places)
// Approach:
// Traverse the array. While traversing, use the absolute value of every element as an index and make the value at this index as negative to mark it visited. If something is already marked negative then this is the repeating element. To find missing, traverse the array again and look for a positive value.

// // C++ program to Find the repeating
// // and missing elements

// #include <bits/stdc++.h>
// using namespace std;

// void printTwoElements(int arr[], int size)
// {
//     int i;
//     cout << " The repeating element is ";

//     for (i = 0; i < size; i++)
//     {
//         if (arr[abs(arr[i]) - 1] > 0)
//             arr[abs(arr[i]) - 1] = -arr[abs(arr[i]) - 1];
//         else
//             cout << abs(arr[i]) << "\n";
//     }

//     cout << "and the missing element is ";
//     for (i = 0; i < size; i++)
//     {
//         if (arr[i] > 0)
//             cout << (i + 1);
//     }
// }

// /* Driver code */
// int main()
// {
//     int arr[] = {7, 3, 4, 5, 5, 6, 2};
//     int n = sizeof(arr) / sizeof(arr[0]);
//     printTwoElements(arr, n);
// }

// // This code is contributed by Shivi_Aggarwal
// Output:

// The repeating element is 5
// and the missing element is 1

// Time Complexity: O(n)

int *findTwoElement(int *arr, int n)
{
    int sum = arr[0];
    int *ans = new int[2];

    for (int i = 1; i < n; i++)
        sum ^= arr[i];

    for (int i = 1; i <= n; i++)
        sum ^= i;

    // now sum = xor of missing and repeating elemement

    int rightMostSetbitPosn = sum & ~(sum - 1);

    int x = 0;
    int y = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] & rightMostSetbitPosn)
            y ^= arr[i];
        else
            x ^= arr[i];
    }
    for (int i = 1; i <= n; i++)
    {
        if (i & rightMostSetbitPosn)
            y ^= i;
        else
            x ^= i;
    }

    int present = 0;
    for (int i = 0; i < n; i++)
    {
        if (x == arr[i])
        {
            present = 1;
            break;
        }
    }

    if (present)
    {
        ans[0] = x;
        ans[1] = y;
    }
    else
    {
        ans[0] = y;
        ans[1] = x;
    }

    return ans;
}