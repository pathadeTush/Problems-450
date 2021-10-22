//Complete this function
//Function to check whether there is a subarray present with 0-sum or not.

// logic if we got prefix sum again which we got previously at some point
// means we must have some elements in between such that their sum = 0
bool subArrayExists(int arr[], int n)
{

    unordered_map<int, int> mp; // (prefix sum, presence)  hash map
    int prefixSum = 0;

    for (int i = 0; i < n; i++)
    {
        prefixSum += arr[i];

        if (prefixSum == 0 || mp[prefixSum])
            return true;

        mp[prefixSum] = 1;
    }

    return false;
}