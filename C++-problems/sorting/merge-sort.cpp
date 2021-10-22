#include <iostream>
using namespace std;

void merge(int arr[], int low, int mid, int high)
{
    int first1 = low, last1 = mid, first2 = mid + 1, last2 = high,
        index = 0, tempArr[high - low + 1];

    while (first1 <= last1 && first2 <= last2)
    {
        if (arr[first1] > arr[first2])
        {
            tempArr[index++] = arr[first2];
            first2++;
        }
        else
        {
            tempArr[index++] = arr[first1];
            first1++;
        }
    }

    // if first1 != last1 then store remaining element in tempArr
    for (; first1 <= last1; first1++)
        tempArr[index++] = arr[first1];

    // if first2 != last1 then store remaining element in tempArr
    for (; first2 <= last2; first2++)
        tempArr[index++] = arr[first2];

    // copy element of tempArr to arr
    for (int i = 0; i < index; i++)
        arr[low + i] = tempArr[i];

    return;
}

void mergeSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);

        merge(arr, low, mid, high);
    }
}

int main()
{
    int size;
    cin >> size;

    int arr[size];
    for (int i = 0; i < size; i++)
        cin >> arr[i];

    mergeSort(arr, 0, size - 1);

    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";

    return 0;
}

// Merging two sorted arrays of size k

//     Best -case : All the elements in the first array are smaller(or larger) 
//                  than all the elements in the second array.
//                  The number of moves : 2k + 2k 
//                  The number of key comparisons : k 
    
//     Worst - case : The number of moves : 2k + 2k 
//                    The number of key comparisons : 2k - 1

//     Worst - case –  O(n * log2n)

// Mergesort is extremely efficient algorithm with respect to time.
// Both worst case and average cases are O (n * log2n )

// But, mergesort requires an extra array whose size equals to the size of the original array.

// If we use a linked list, we do not need an extra array 
// But, we need space for the links
// And, it will be difficult to divide the list into half ( O(n) )