/*

Merge two binary Max heaps
Easy Accuracy: 51.98% Submissions: 2988 Points: 2

Given two binary max heaps as arrays, merge the given heaps to form a new max heap.

 

Example 1:

Input  : 
n = 4 m = 3
a[] = {10, 5, 6, 2}, 
b[] = {12, 7, 9}
Output : 
{12, 10, 9, 2, 5, 7, 6}
Explanation :



 

 

Your Task:  
You don't need to read input or print anything. Your task is to complete the function mergeHeaps() which takes the array a[], b[], its size n and m, as inputs and return the merged max heap.

 

Expected Time Complexity: O(n.Logn)
Expected Auxiliary Space: O(1)

 

Constraints:
1 <= n, m <= 105
1 <= a[i], b[i] <= 2*105

*/
// { Driver Code Starts
// Initial Template for C++

// C++ program to merge two max heaps.

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
  void heapify(vector<int> &arr, int n, int i)
  {
    int l = 2 * i + 1, r = 2 * i + 2;
    int rear = n - 1;
    while (l <= rear)
    {
      if (l == rear)
      {
        if (arr[i] < arr[l])
          swap(arr[i], arr[l]);
        return;
      }
      if (arr[i] >= arr[l] and arr[i] >= arr[r])
        return;

      int mx = arr[l] >= arr[r] ? l : r;

      swap(arr[mx], arr[i]);

      i = mx;
      l = 2 * i + 1;
      r = 2 * i + 2;
    }

    return;
  }

  vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m)
  {

    for (int i = 0; i < m; i++)
      a.push_back(b[i]);

    for (int i = (n + m) >> 1 - 1; i >= 0; i--)
      heapify(a, n + m, i);

    return a;
  }
};

// { Driver Code Starts.

bool isMerged(vector<int> &arr1, vector<int> &arr2, vector<int> &merged)
{
  if (arr1.size() + arr2.size() != merged.size())
  {
    return false;
  }
  arr1.insert(arr1.end(), arr2.begin(), arr2.end());
  sort(arr1.begin(), arr1.end());
  vector<int> mergedCopy = merged;
  sort(mergedCopy.begin(), mergedCopy.end());
  if (arr1 != mergedCopy)
  {
    return false;
  }
  for (int i = 1; i < merged.size(); i++)
  {
    if (merged[i] > merged[(i - 1) / 2])
      return false;
  }
  return true;
}
int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n, m, i;
    cin >> n >> m;
    vector<int> a(n, 0), b(m, 0);
    for (i = 0; i < n; i++)
    {
      cin >> a[i];
    }
    for (i = 0; i < m; i++)
    {
      cin >> b[i];
    }
    vector<int> merged, copyA = a, copyB = b;
    Solution obj;
    merged = obj.mergeHeaps(a, b, n, m);
    bool flag = isMerged(copyA, copyB, merged);
    if (flag == false)
      cout << 0 << endl;
    else
      cout << 1 << endl;
  }
  return 0;
}
// } Driver Code Ends