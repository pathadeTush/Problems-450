#include <bits/stdc++.h>

void multiply(int n, vector<int> &v)
{
    int len = v.size();
    int carry = 0;
    for (int i = 0; i < len; i++)
    {
        int prod = v[i] * n + carry;

        carry = prod / 10;
        v[i] = prod % 10;
    }

    while (carry)
    {
        v.push_back(carry % 10);
        carry /= 10;
    }

    return;
}

vector<int> factorial(int n)
{
    vector<int> fact;

    fact.push_back(1);

    for (int i = 2; i <= n; i++)
        multiply(i, fact);

    reverse(fact.begin(), fact.end());

    return fact;
}