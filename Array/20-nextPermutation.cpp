/*
1) An sequence sorted in descending order does not have next permutation. For example edcba” does not have next permutation.
2) For a sequence which is not sorted in descending order for example “abedc”, we can follow below steps.
……….a) Traverse from right and find the first item that is not following the descending order. For example in “abedc”, the character ‘b’ does not follow the descending order.
……….b) Swap the found character with closest greater (or smallest greater) element on right side of it. In case of “abedc”, we have ‘c’ as the closest greater element. After swapping ‘b’ and ‘c’, string becomes “acedb”.
……….c) After swapping, sort the string after the position of character found in step a. After sorting the substring “edb” of “acedb”, we get “acbde” which is the required next permutation.

Optimizations in step b) and c)
a) Since the sequence is sorted in decreasing order, we can use binary search to find the closest greater element.
c) Since the sequence is already sorted in decreasing order (even after swapping as we swapped with the closest greater), we can get the sequence sorted (in increasing order) after reversing it.
*/

class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        int n = nums.size();
        int index = -1;

        for (int i = n - 2; i >= 0; i--)
        {
            if (nums[i] < nums[i + 1])
            {
                index = i;
                break;
            }
        }

        if (index == -1)
            reverse(nums.begin(), nums.end());
        else
        {
            int diff = INT_MAX;
            int smallestGreator = index;
            for (int i = n - 1; i > index; i--)
            {
                if (nums[i] > nums[index] and abs(nums[i] - nums[index]) < diff)
                {
                    diff = abs(nums[i] - nums[index]);
                    smallestGreator = i;
                }
            }
            swap(nums[index], nums[smallestGreator]);
            reverse(nums.begin() + index + 1, nums.end());
        }

        return;
    }
};