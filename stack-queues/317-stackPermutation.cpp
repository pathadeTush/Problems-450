#include <bits/stdc++.h>
using namespace std;
/*
Input : First array: 1, 2, 3  
        Second array: 2, 1, 3
Output : Yes

st -> 1 2  i = 2, j = 0
st -> 1    i = 2, j = 1
st ->      i = 2, j = 2
st -> 3    i = 3, j = 2
st ->      i = 3, j = 3
*/

bool isPermutation(int pushed[], int popped[], int n)
{
    if (n == 0)
        return true;

    stack<int> st;
    int i = 0, j = 0;
    while (i < n)
    {
        if(st.empty())
            st.push(pushed[i++]);
        while (st.top() != popped[j] and i < n)
        {
            st.push(pushed[i++]);
        }
        st.pop();
        j++;
    }

    while (!st.empty() and j < n and st.top() == popped[j])
    {
        st.pop();
        j++;
    }
    if (st.empty() and j >= n)
        return true;

    return false;
}

int main()
{
    int n;
    cin >> n;

    int pushed[n], popped[n];
    for (int i = 0; i < n; i++)
        cin >> pushed[i];
    for (int i = 0; i < n; i++)
        cin >> popped[i];

    cout << isPermutation(pushed, popped, n) << endl;

    return 0;
}