
// Time complexity: O(n+m)
// space complexity: O(n+m)
// double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
// {

//     vector<int> v;
//     int i = 0, j = 0;

//     for (; i < nums1.size() and j < nums2.size();)
//     {
//         if (nums1[i] <= nums2[j])
//         {
//             v.push_back(nums1[i]);
//             i++;
//         }
//         else
//         {
//             v.push_back(nums2[j]);
//             j++;
//         }
//     }

//     while (i < nums1.size())
//     {
//         v.push_back(nums1[i]);
//         i++;
//     }
//     while (j < nums2.size())
//     {
//         v.push_back(nums2[j]);
//         j++;
//     }

//     if (v.size() % 2 != 0)
//         return v[v.size() / 2];
//     else
//         return (v[v.size() / 2 - 1] + v[v.size() / 2]) / 2.0;
// }

// Time complexity: O(log(n+m))
// space complexity: O(1)
double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
{
    int n1 = nums1.size();
    int n2 = nums2.size();
    int n = n1 + n2;
    int k = 0;
    int ans = 0;
    int i = 0, j = 0;

    int isEven = 1;

    if (n % 2 != 0)
    {
        isEven = 0;
        n++;
    }

    for (; i < n1 and j < n2 and k < n / 2;)
    {
        if (nums1[i] <= nums2[j])
        {
            ans = nums1[i];
            i++;
            k++;
        }
        else
        {
            ans = nums2[j];
            j++;
            k++;
        }
    }

    int temp;
    if (i < n1 and j < n2)
    {
        if (nums1[i] <= nums2[j])
            temp = nums1[i];
        else
            temp = nums2[j];

        if (!isEven)
            return ans;

        ans += temp;

        return ans / 2.0;
    }
    else
    {
        while (i < n1 and k < n / 2)
        {
            ans = nums1[i];
            i++;
            k++;
        }
        while (j < n2 and k < n / 2)
        {
            ans = nums2[j];
            j++;
            k++;
        }

        if (!isEven)
            return ans;

        if (i < n1)
            temp = nums1[i];
        else
            temp = nums2[j];

        ans += temp;

        return ans / 2.0;
    }
}