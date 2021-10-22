
// a1 + a2 = k
class Solution
{
public:
    int getPairsCount(int arr[], int n, int k)
    {

        unordered_map<int, int> mp; // arr[i], frequency

        for (int i = 0; i < n; i++)
        {
            mp[arr[i]]++;
        }

        int count = 0;
        for (int i = 0; i < n; i++)
        {
            count += mp[k - arr[i]]; // check for how many a1 such that a1 + a2(arr[i]) = k

            if (k - arr[i] == arr[i]) // if a1 and a2 are same then pair will countd as 4 times
                count--;
        }

        return count / 2; // each pair will be counted twice
    }
};