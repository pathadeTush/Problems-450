class Solution
{
public:
    //Function to rotate matrix anticlockwise by 90 degrees.
    void rotateby90(vector<vector<int>> &matrix, int n)
    {
        int m = n;

        // transpose
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // reverse each column
        for (int col = 0; col < m; col++)
        {
            int start = 0, end = n - 1;
            while (start < end)
            {
                swap(matrix[start][col], matrix[end][col]);
                start++;
                end--;
            }
        }

        return;
    }
};