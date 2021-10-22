int findPosition(int n)
{
    if (n == 0)
        return -1;

    int position = 0;
    bool isOnlySetbit = false;
    while (n)
    {
        if ((n & 1) and !isOnlySetbit)
            isOnlySetbit = true;

        else if ((n & 1) and isOnlySetbit)
            return -1;

        position++;
        n = n >> 1;
    }

    return position;
}