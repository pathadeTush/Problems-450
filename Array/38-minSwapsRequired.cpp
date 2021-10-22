int minSwap(int *arr, int n, int k)
{

    int ans = 0;
    int totalSmallEle = 0;
    int greaterEleCount = 0;

    // calculate total smaller element in an array
    for (int i = 0; i < n; i++)
        if (arr[i] <= k)
            totalSmallEle++;

    // now for each window of size totalSmallEle  count all \
       greater element in that window and update ans as min(ans, greaterEleCount)

    for (int i = 0; i < totalSmallEle; i++)
        if (arr[i] > k)
            greaterEleCount++;

    ans = greaterEleCount;

    for (int i = 0, j = totalSmallEle; j < n; i++, j++)
    {
        if (arr[i] > k)
            greaterEleCount--; // decrement previous windows's count of greater element

        if (arr[j] > k)
            greaterEleCount++;

        ans = min(ans, greaterEleCount);
    }

    return ans;
}
