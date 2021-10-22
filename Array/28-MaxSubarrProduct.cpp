// Function to find maximum product subarray
long long maxProduct(int *arr, int n)
{
    long long maxProduct = LLONG_MIN;
    long long prod = 1;
    long long prodTillFirstNeg = 1;
    long long prevProd = 1;

    for (int i = 0; i < n; i++)
    {
        prod *= arr[i];

        // store product till first negative number in current subarray
        if (prodTillFirstNeg > 0)
            prodTillFirstNeg *= arr[i];

        // if arr[i] == 0 and if prod till i-1 for prev subarr is < 0 then
        // divide prevProd by product till first negative number in that subarr
        if (arr[i] == 0 && prevProd < 0)
            maxProduct = max(maxProduct, prevProd / prodTillFirstNeg);

        // if we reach at end of array and prod < 0 then
        // divide prod by product till first negative number in that subarr
        else if (i == n - 1 && prod < 0)
            maxProduct = max(maxProduct, prod / prodTillFirstNeg);
        else
            maxProduct = max(maxProduct, prod);

        // if arr[i] == 0 then update prod and prodTillFirstNeg to 1
        if (arr[i] == 0)
        {
            prod = 1;
            prodTillFirstNeg = 1;
        }

        prevProd = prod;
    }

    return maxProduct;
}