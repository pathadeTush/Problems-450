 // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    
    long long merge(long long arr[], long long l, long long mid, long long r){
        long long start1 = l, start2 = mid+1;
        long long invCnt = 0;
        long long temp[r-l+1], idx = 0;
        
        while(start1 <= mid and start2 <= r){
            if(arr[start1] <= arr[start2]){
                temp[idx++] = arr[start1++];
            }
            else{
                temp[idx++] = arr[start2++];
                invCnt += mid - start1 + 1;
            }
        }
        
        while(start1 <= mid) temp[idx++] = arr[start1++];
        while(start2 <= r) temp[idx++] = arr[start2++];
        
        for(long long i = 0; i < idx; i++)
            arr[l+i] = temp[i];
            
        return invCnt;
    }
    
    
    long long mergeSort(long long arr[], long long l, long long r){
        long long invCnt = 0;
        if(l < r){
            long long mid  = (l + r) >> 1;
            
            invCnt += mergeSort(arr, l, mid);
            invCnt += mergeSort(arr, mid + 1, r);
            
            invCnt += merge(arr, l, mid, r);
        }
        
        return invCnt;
    }
    
    
    long long int inversionCount(long long arr[], long long N)
    {
        if(N == 0 || N == 1) return 0;
        
        return mergeSort(arr, 0, N-1);
    }
