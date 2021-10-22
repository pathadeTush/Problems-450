/*
sort the array. Then take the min of difference of boundary value of each window of size m.
*/
long long findMinDiff(vector<long long> a, long long n, long long m)
{
    sort(a.begin(), a.end());

    long long minDiff = a[m - 1] - a[0];
    long long i = 1, j = m;
    while (j < n)
    {
        minDiff = min(minDiff, a[j] - a[i]);
        i++;
        j++;
    }

    return minDiff;
}