#include <iostream>
using namespace std;

int main()
{
    int size;
    cin >> size;

    int arr[size];
    for (int i = 0; i < size; i++)
        cin >> arr[i];

    bool sorted = false;
    int i = 0, temp;
    while (i < size - 1 && !sorted)
    {
        sorted = true;
        for (int j = 0; j < size - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

                sorted = false;
            }
        }
        i++;
    }

    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";

    return 0;
}

// The list is divided into two sublists : sorted and unsorted.
// The smallest element is bubbled from the unsorted list and moved to the sorted sublist.
// After that, the wall moves one element ahead, increasing the number of sorted elements
// and decreasing the number of unsorted ones.
// Each time an element moves from the unsorted part to the sorted part one sort pass is
// completed.
// Given a list of n elements, bubble sort requires up to n - 1 passes to sort the data.

// Best - case :		 O(n)
// Array is already sorted in ascending order.
// The number of moves : 3 * no. of swaps 		 O(1)
// The number of key comparisons : (n - 1) 	 O(n)

// Worst - case : 	 O(n^2)
// Array is in reverse order : Outer loop is executed n - 1 times,
// The number of moves : 3 * (1 + 2 + ... + n - 1) = 3 * n * (n - 1) / 2 		 O(n^2)
// The number of key comparisons : (1 + 2 + ... + n - 1) = n * (n - 1) / 2 	 O(n^2)

// Average - case : 	 O(n^2)
// We have to look at all possible initial data organizations.
// So,Bubble Sort is O(n^2)