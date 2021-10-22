bool find3Numbers(int arr[], int n, int x)
{

    sort(arr, arr + n);

    for (int i = 0; i < n; i++)
    {
        int sum = x - arr[i];
        int sumOf2 = 0;

        int j = 0, k = n - 1;

        while (j < k)
        {
            if (j == i)
                j++;
            if (k == i)
                k--;

            sumOf2 = arr[j] + arr[k];

            if (sum == sumOf2)
                return true;

            if (sumOf2 > sum)
                k--;
            else
                j++;

            sumOf2 = 0;

            // cout <<"i " << i << "  j: "<< j << " k: "<< k << " sumof2: "<<sumOf2 << " sum: "<< sum<< endl;
        }
    }

    return false;
}