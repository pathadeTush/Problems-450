// Time complexity: O(n)
// Space complexity: O(n)
// int trappingWater(int arr[], int n){

//     if(n == 0 || n == 1 || n == 2) return 0;

//     int boundary[n]; // it will store the minimun(longestLeftBoundary, longestRightBoundary)
//     boundary[0] = arr[0];
//     boundary[n-1] = arr[n-1];

//     // first store the logestLeftBoundary
//     int leftBoundary = INT_MIN;
//     for(int i = 1; i < n - 1; i++){
//         leftBoundary = max(leftBoundary, arr[i-1]);
//         boundary[i] = leftBoundary;
//     }

//     // Now store the minimun(longestLeftBoundary, longestRightBoundary)
//     int rightBoundary = INT_MIN;
//     for(int i = n-2; i > 0; i--){
//         rightBoundary = max(rightBoundary, arr[i+1]);
//         boundary[i] = min(boundary[i] ,rightBoundary);
//     }

//     // Now for each i, amt of water = boundary[i] = height(i);
//     int ans = 0;
//     for(int i = 0; i < n; i++){
//         int waterAmt = boundary[i] - arr[i];
//         if(waterAmt >= 0)
//             ans += waterAmt;
//     }

//     return ans;
// }

// Time complexity: O(n)
// Space complexity: O(1)

int trappingWater(int arr[], int n)
{
    int capacity = 0, lmax = arr[0], rmax = arr[n - 1];

    int l = 0, r = n - 1;

    while (l < r)
    {
        lmax = max(lmax, arr[l]);
        rmax = max(rmax, arr[r]);

        capacity += (lmax > rmax) ? (rmax - arr[r--]) : (lmax - arr[l++]);
    }

    return capacity;
}
