
#include <iostream>
#include <vector>
using namespace std;

int t = 0;

inline bool check(vector<int> arr, int n)
{
    //bool sorted = true;

    for (int i = 1; i < n; i++)
    {
        if (arr[i] < arr[i - 1])
            return false;
    }

    return true;
}

bool per(vector<int> arr, int size, int n, int &ans)
{
    t++;

    if (size == 1)
    {
        if (check(arr, n))
        {
            return true;
        }
        return false;
    }

    for (int i = 0; i < size; i++)
    {
        ans++;
        //per(arr, n - 1, n, ans);
        if (per(arr, size - 1, n, ans))
            return true;
        if (size % 2 == 1)
        {
            int temp = arr[0];
            arr[0] = arr[size - 1];
            arr[size - 1] = temp;
        }
        else
        {
            int temp = arr[i];
            arr[i] = arr[size - 1];
            arr[size - 1] = temp;
        }
    }

    return true;
}

int main()
{
    // Write your code here

    int n;
    cin >> n;

    int ans = 0;

    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    //per(arr, n, n, ans);

    cout << math.f

    return 0;
}