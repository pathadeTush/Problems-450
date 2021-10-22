// Function to find number of bits needed to be flipped to convert A to B
int countBitsFlip(int a, int b)
{

    int ans = 0;

    while (a || b)
    {
        if ((a & 1) ^ (b & 1))
            ans++;
        a = a >> 1;
        b = b >> 1;
    }

    return ans;
}