void rotate(int arr[], int n)
{
    for (int j = n - 1; j > 0; j--)
    {
        int temp = arr[j];
        arr[j] = arr[j - 1];
        arr[j - 1] = temp;
    }
    return;
}