int sb(int arr[], int n, int x)
{
    int sum = 0;
    int minLength = n;
    int l = 0;
    int startIndexOfSubarr = 0;

    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        l++;
        while (sum > x)
        {
            minLength = min(minLength, l);
            sum -= arr[startIndexOfSubarr];
            l--;
            startIndexOfSubarr++;
        }
    }

    return minLength;
}