/*

    The idea is to find the pivot point, divide the array in two sub-arrays and perform binary search.
    The main idea for finding pivot is – for a sorted (in increasing order) and pivoted array, pivot element is the only element for which next element to it is smaller than it.
    Using the above statement and binary search pivot can be found.
    After the pivot is found out divide the array in two sub-arrays.
    Now the individual sub – arrays are sorted so the element can be searched using Binary Search.
    
*/

int binarySearch(int l, int r, vector<int> &arr, int target)
{
    while (l <= r)
    {
        int mid = (l + r) >> 1;

        if (arr[mid] == target)
            return mid;

        if (arr[mid] > target)
            r = mid - 1;

        else
            l = mid + 1;
    }

    return -1;
}

int search(vector<int> &arr, int target)
{

    if (arr.size() == 0)
        return -1;
    if (arr.size() == 1)
        return (arr[0] == target) ? 0 : -1;

    int indexOfRotation = 0;

    while (indexOfRotation + 1 < arr.size() and arr[indexOfRotation] < arr[indexOfRotation + 1])
        indexOfRotation++;

    int leftSubarrRes = binarySearch(0, indexOfRotation, arr, target);

    if (leftSubarrRes != -1)
        return leftSubarrRes;

    int rightSubarrRes = binarySearch(indexOfRotation + 1, arr.size() - 1, arr, target);

    return (rightSubarrRes == -1) ? -1 : rightSubarrRes;
}

/*

// returns index of smallest element
    int getPivot(int arr[], int l, int h)
    {
    
        if (l == h || l == h+1)
            return -1;
    
        // check if array is not rotated
        if (arr[l] <= arr[h])
            return -1;
    
        int low = l;
        int high = h;
        int mid;
    
        while (low < high)
        {
            mid = (low + high) >> 1;
    
            if (arr[mid] > arr[high])
                low = mid + 1;
            else
                high = mid; // not mid-1 because in that case we are loosing midth element. It also might be pivot
        }
    
        return low; // here low = mid = high
    }

    int binarySearch(int a[], int l, int h, int k){
        int low = l, high = h;
        
        while(low <= high){
            int mid = (low + high) >> 1;
            
            if(a[mid] == k)
                return mid;
            if(a[mid] > k)
                high = mid-1;
            else
                low = mid+1;
        }
        
        return -1;
    }
    
    int search(int a[], int l, int h, int k){
        int pivot = getPivot(a, l, h); 
        
        int isFound = binarySearch(a, l, pivot-1, k);
        
        if(isFound != -1) return isFound;
        
        isFound = binarySearch(a, pivot, h, k);
        
        return isFound;
    }

*/