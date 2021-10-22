/*

first sort the intervals to get exact non overlapping intervals from following logic.

Now for each ith interval check following condition

    1. end of(i) >= start of (i+1)
    2. start of(i) <= end of (i+1)

    if above two condition statisfy then i and i+1 intervals are overlapping and we can merge them
    into 1 intervals with start and end points are as follows

    start = min(start of(i), start of(i+1))
    end = max(end of(i), end of(i)) 

*/

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        vector<vector<int>> ans;

        // first sort the intervals to get exact non overlapping intervals from following logic.
        sort(intervals.begin(), intervals.end());

        for (int i = 0; i < intervals.size(); i++)
        {
            int start = intervals[i][0];
            int end = intervals[i][1];
            while (i < intervals.size() - 1 && (end >= intervals[i + 1][0] && start <= intervals[i + 1][1]))
            {
                start = min(start, intervals[i + 1][0]);
                end = max(end, intervals[i + 1][1]);
                i++;
            }
            ans.push_back({start, end});
        }

        return ans;
    }
};
