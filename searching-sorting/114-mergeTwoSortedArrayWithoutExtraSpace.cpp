class Solution
{
public:
    /*

Logic

1. Put all n small elements in arr1
2. Sort both array

To put all small elements in arr1
keep two counter i, j

i pointing to last of arr1
j pointing to start of arr2


now check arr1[i] arr2[j] 
    if arr1[i] > arr2[j] 
        then swap them  // as all rest elements of arr1 are smaller than arr1[i] 
        do i--, j++   
    else
        break // we have got all small elements in arr1 and arr2 will have all elements greator than arr1 elements
        
        
// Now sort arr1 and arr2 individualy        

*/
    void merge(int arr1[], int arr2[], int n, int m)
    {

        int j = 0, i = n - 1;

        while (i >= 0 and j < m)
        {
            if (arr1[i] > arr2[j])
            {
                swap(arr1[i], arr2[j]);
                i--;
                j++;
            }
            else
                break;
        }

        sort(arr1, arr1 + n);
        sort(arr2, arr2 + m);

        return;
    }
};