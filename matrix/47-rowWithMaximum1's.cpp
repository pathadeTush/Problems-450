class Solution
{
public:
    // binary search
    int countOfEleGreatorThanEqualTo(vector<int> row, int num)
    {

        int l = 0;
        int r = row.size() - 1;
        while (l <= r)
        {
            int mid = (l + r) >> 1;

            if (row[mid] < num)
                l = mid + 1;
            else
                r = mid - 1;
        }

        return row.size() - l;
    }

    int rowWithMax1s(vector<vector<int>> arr, int n, int m)
    {
        int maxRow = -1;
        int count = 0;
        for (int row = 0; row < n; row++)
        {
            int k = countOfEleGreatorThanEqualTo(arr[row], 1);
            if (count < k)
            {
                count = k;
                maxRow = row;
            }
        }

        return maxRow;
    }
};