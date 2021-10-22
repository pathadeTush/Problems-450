/*
store positive element in one array
store negative element in 2nd array

and store pos and neg elements in original array alternatively
*/

void rearrange(int arr[], int n)
{
    vector<int> pos;
    vector<int> neg;

    for (int i = n - 1; i >= 0; i--)
    {
        if (arr[i] >= 0)
            pos.push_back(arr[i]);
        else
            neg.push_back(arr[i]);
    }
    int i = 0;
    while (i < n)
    {
        if (pos.size() && neg.size())
        {
            if (i % 2 == 0)
            {
                arr[i++] = pos.back();
                pos.pop_back();
            }
            else
            {
                arr[i++] = neg.back();
                neg.pop_back();
            }
        }
        else
            break;
    }

    while (i < n && pos.size())
    {
        arr[i++] = pos.back();
        pos.pop_back();
    }
    while (i < n && neg.size())
    {
        arr[i++] = neg.back();
        neg.pop_back();
    }
    return;
}