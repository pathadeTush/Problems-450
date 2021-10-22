// n: input to count the number of set bits
//Function to return sum of count of set bits in the integers from 1 to n.
int countSetBits(int n)
{
    if (n == 1)
        return 1;
    if (n == 0)
        return 0;

    int x = log2(n); // largestPowerOf2 nearer to n

    int setBits = x * (1 << (x - 1)); // setBits till 2^x -1  = x * 2^(x-1)
    int msb = n - (1 << x) + 1;       // msb from 2^x to n

    return setBits + msb + countSetBits(n - (1 << x));
}