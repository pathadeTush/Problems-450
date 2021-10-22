void threeWayPartition(vector<int> &arr, int a, int b)
{
    int n = arr.size() - 1;
    int start = 0, end = n - 1;

    int i = 0;
    while (i <= end)
    {

        if (arr[i] < a)
            swap(arr[i++], arr[start++]);

        else if (arr[i] > b)
            swap(arr[i], arr[end--]);

        else
            i++;
    }

    return;
}