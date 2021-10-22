class Solution
{
public:
    // binary search to find countOfEleLessThanEqualTo n in a row
    int countOfEleLessThanEqualTo(vector<int> row, int n)
    {

        int l = 0;
        int r = row.size() - 1;
        int mid;

        while (l <= r)
        {
            mid = (l + r) >> 1;

            if (row[mid] <= n)
                l = mid + 1;
            else
                r = mid - 1;
        }

        return l; // here l will go beyond r and it will store the count of \
                     num less than or equal to n
    }

    int median(vector<vector<int>> &matrix, int r, int c)
    {
        int low = 1;
        int high = 2000;

        // count all elements which are lesser than mid in each row
        // expected count should be = (r*c)/2
        // if we get such count then move towards left until (element to its left should not be equal to itself)
        // that's why we have taken = sign with < operator
        // binary search to find median

        while (low <= high)
        {
            int mid = (low + high) >> 1;
            int count = 0;

            for (int row = 0; row < r; row++)
            {
                count += countOfEleLessThanEqualTo(matrix[row], mid);
            }

            // for equal sign it will not count duplicate element as separate one.
            if (count <= (r * c) / 2)
                low = mid + 1;
            else
                high = mid - 1;
        }

        return low;
    }
};