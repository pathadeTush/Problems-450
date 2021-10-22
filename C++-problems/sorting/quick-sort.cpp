#include <iostream>
using namespace std;

int partition(int arr[], int low, int high)
{
    int pivot = arr[low];

    int i = low, j = high;

    while (i < j)
    {
        while (arr[i] <= pivot)
            i++;

        while (arr[j] > pivot)
            j--;

        if (i < j)
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[j];
    arr[j] = pivot;
    arr[low] = temp;

    return j;
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pivot = partition(arr, low, high);

        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }

    return;
}

int main()
{
    int size;
    cin >> size;

    int arr[size];
    for (int i = 0; i < size; i++)
        cin >> arr[i];

    quickSort(arr, 0, size - 1);

    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";

    return 0;
}

// Best case running time : O(n*log2n)
// Worst case running time: O(n^2)

// Quicksort is O(n *log2n) in the best case and average case.
// Quicksort is slow when the array is sorted and we choose the first element as the pivot.
// Although the worst case behavior is not so good, its average case behavior is much better than its worst case.So, Quicksort is one of best sorting algorithms using key comparisons.
