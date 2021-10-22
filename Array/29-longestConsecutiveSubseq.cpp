// arr[] : the input array
// N : size of the array arr[]

// O(nxlog(n))
//Function to return length of longest subsequence of consecutive integers.
int findLongestConseqSubseq(int arr[], int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;

    sort(arr, arr + n);
    int count = 0, maxCount = INT_MIN;
    int prev = arr[0];

    for (int i = 0; i < n; i++)
    {
        if (arr[i] - prev == 1)
            count++;
        else if (arr[i] == prev)
            continue;
        else
            count = 0;

        prev = arr[i];
        maxCount = max(maxCount, count);
    }

    return maxCount + 1;
}

// hashing  o(n)