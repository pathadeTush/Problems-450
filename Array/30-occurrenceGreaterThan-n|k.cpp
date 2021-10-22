//Function to find all elements in array that appear more than n/k times.
int countOccurence(int arr[], int n, int k)
{

    map<int, int> mp; // element, freq

    for (int i = 0; i < n; i++)
        mp[arr[i]]++;

    int count = 0;
    for (int i = 0; i < mp.size(); i++)
        if (mp[i] > (n / k))
            count++;

    return count;
}