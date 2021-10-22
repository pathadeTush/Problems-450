#include <bits/stdc++.h>
using namespace std;

int maxSum(int a1[], int a2[], int n, int m)
{
    int i = 0, j = 0;
    int sum = 0, s1 = 0, s2 = 0;
    while (i < n and j < m)
    {
        if (a1[i] < a2[j])
        {
            s1 += a1[i];
            i++;
        }
        else if (a1[i] > a2[j])
        {
            s2 += a2[j];
            j++;
        }

        else
        {
            sum += max(s1, s2) + a1[i];
            s1 = 0;
            s2 = 0;
            i++;
            j++;
        }
    }

    while (i < n)
        s1 += a1[i++];
    while (j < m)
        s2 += a2[j++];

    sum += max(s1, s2);

    return sum;
}

int main()
{
    int n, m;
    cin >> n >> m;
    int a1[n], a2[m];

    for (int i = 0; i < n; i++)
        cin >> a1[i];
    for (int i = 0; i < m; i++)
        cin >> a2[i];

    cout << maxSum(a1, a2, n, m) << endl;

    return 0;
}