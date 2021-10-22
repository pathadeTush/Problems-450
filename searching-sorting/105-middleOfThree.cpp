int middle(int A, int B, int C)
{
    return A + B + C - max(max(A, B), C) - min(min(A, B), C);
}