#include <iostream>
using namespace std;

int main()
{
    // your code goes here
    int t;
    scanf("%d", &t);
    while (t--)
    {
        long long int n, d, h;
        scanf("%lld", &n);
        scanf("%lld", &d);
        scanf("%lld", &h);

        long long int amt = 0;
        bool alert = false;
        for (long long int i = 0; i < n; i++)
        {
            long long int ai;
            scanf("%lld", &ai);
            if (ai > 0)
            {
                amt += ai;
            }
            else
            {
                amt = max(amt - d, (long long)0);
            }

            if (amt > h)
            {
                alert = true;
                break;
            }
        }
        if (alert)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
