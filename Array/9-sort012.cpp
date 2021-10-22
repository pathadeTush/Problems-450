
void sort012(int a[], int n)
{
    int count0 = 0, count1 = 0, count2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 0)
            count0++;
        else if (a[i] == 1)
            count1++;
        else
            count2++;
    }

    count1 += count0;
    count2 += count1;

    for (int i = 0; i < n; i++)
    {
        if (i < count0)
            a[i] = 0;
        else if (i >= count0 && i < count1)
            a[i] = 1;
        else
            a[i] = 2;
    }

    return;
}