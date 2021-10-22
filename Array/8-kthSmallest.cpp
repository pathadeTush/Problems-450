// arr : given array
// l : starting index of the array i.e 0
// r : ending index of the array i.e size-1
// k : find kth smallest element and return using this function

/*
store k+1 element in a maxHeap. we will have largest element on top 
which is greator than kth smallest element in an array.
So pop it from heap and continue.

at the end of loop. we will have exactly k smaller elements in heap.
And as it is maxHeap so we will have kth smallest at the top.

*/

int kthSmallest(int arr[], int l, int r, int k)
{
    priority_queue<int> maxHeap; // max heap

    for (int i = l; i <= r; i++)
    {
        maxHeap.push(arr[i]);
        if (maxHeap.size() > k)
            maxHeap.pop();
    }

    return maxHeap.top();
}