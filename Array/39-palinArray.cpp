int PalinArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int reversedNum = 0, rem = 0, num = a[i];
        while (num > 0)
        {
            rem = num % 10;
            reversedNum = (reversedNum * 10) + rem;
            num /= 10;
        }
        if (reversedNum != a[i])
            return 0;
    }

    return 1;
}