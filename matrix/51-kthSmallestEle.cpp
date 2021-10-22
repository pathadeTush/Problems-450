
#include <bits/stdc++.h>
using namespace std;

// This returns count of elements in matrix less than of equal to num
int getElementsLessThanOrEqual(int num, int n, int mat[4])
{
    int l = 0;
    int r = n - 1;

    while (l <= r)
    {
        int mid = (l + r) >> 1;

        if (mat[mid] <= num)
            l = mid + 1;
        else
            r = mid - 1;
    }

    return l;
}

// reuturs kth smallest index in the matrix
int kthSmallest(int mat[4][4], int n, int k)
{
    // We know the answer lies between the first and the last element
    // So do a binary search on answer based on the number of elements
    // our current element is greater than the elements in the matrix
    int l = mat[0][0], r = mat[n - 1][n - 1];

    while (l <= r)
    {
        int mid = l + (r - l) / 2;

        int count = 0;
        for (int row = 0; row < n; row++)
            count += getElementsLessThanOrEqual(mid, n, mat[row]);

        // if we use = sign here it will not count duplicate element.
        // like, 1 2 2 3 here 2nd smallest elements are at index 1 and 2
        // if we do not use equal sign then 2nd smallest element is at index
        // 1 and 3rd smallest element is at index  2
        if (count <= k)
            l = mid + 1;
        int mid = (l + r) >> 1;

        if (row[mid] < num)
            l = mid + 1;
        else
            r = mid - 1;
    }
        else
            r = mid - 1;
    }
    return l;
}

int main()
{
    int n = 4;
    int mat[4][4] = {
        {10, 20, 30, 40},
        {15, 25, 35, 45},
        {25, 29, 37, 48},
        {32, 33, 39, 50},
    };
    cout << "7th smallest element is " << kthSmallest(mat, 4, 7);
    return 0;
}

// int kthSmallest(int mat[MAX][MAX], int n, int k)
// {
//     priority_queue<int> maxHeap; // max heap

//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             int prevSize = maxHeap.size();
//             maxHeap.push(mat[i][j]);

//             if (maxHeap.size() > k)
//                 maxHeap.pop();
//         }
//     }
//     return maxHeap.top();
// }
