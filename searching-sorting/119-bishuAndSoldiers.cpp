
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int power[n];
    for (int i = 0; i < n; i++)
        cin >> power[i];

    int q;
    cin >> q;

    while (q--)
    {
        int count = 0;
        int totalPower = 0;
        int m;
        cin >> m;

        for (int i = 0; i < n; i++)
        {
            if (power[i] <= m)
            {
                count++;
                totalPower += power[i];
            }
        }

        cout << count << " " << totalPower << endl;
    }

    return 0;
}