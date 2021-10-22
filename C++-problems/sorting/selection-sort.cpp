#include <iostream>
using namespace std;

int main()
{
    int size;
    cin >> size;
    int arr[size];

    for (int i = 0; i < size; i++)
        cin >> arr[i];

    for (int i = 0; i < size - 1; i++)
    {
        int minIndex = i;

        // calculating minimum element
        for (int j = i + 1; j < size; j++)
            if (arr[minIndex] > arr[j])
                minIndex = j;

        // swapping of arr[i] with minEle
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }

    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";

    return 0;
}

// The list is divided into two sublists, sorted and unsorted, which are divided by an imaginary wall.
// We find the smallest element from the unsorted sublist and swap it with the element at the beginning
// of the unsorted data.After each selection and swapping, the imaginary wall between the two sublists
// move one element ahead, increasing the number of sorted elements and decreasing the number of unsorted
// ones.
// Each time we move one element from the unsorted sublist to the sorted sublist, we say that we have
// completed a sort pass.A list of n elements requires n - 1 passes to completely rearrange the data.

//  Total Swaps : n - 1
//  Total Moves : 3 * (n - 1)(Each swap has three moves)
//  Total key comparisons = 1 + 2 + ... + n - 1 = n * (n - 1) / 2
// Time complexity : O(n^2)

// The best case, the worst case, and the average case of the selection sort algorithm are same.
//  all of them are O(n^2)

// Since O(n2) grows so rapidly, the selection sort algorithm is appropriate only for small n.
// Although the selection sort algorithm requires O(n2) key comparisons, it only requires  O(n) moves.
// A selection sort could be a good choice if data moves are costly but key comparisons are not costly (short keys, long records).
