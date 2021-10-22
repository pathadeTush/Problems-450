#include <bits/stdc++.h>
using namespace std;

void interleave(queue<int> &q, int n)
{
    queue<int> q1, q2;
    for (int i = 0; i < n / 2; i++)
    {
        q1.push(q.front());
        q.pop();
    }
    for (int i = n / 2; i < n; i++)
    {
        q2.push(q.front());
        q.pop();
    }
    for (int i = 0; i < n / 2; i++)
    {
        q.push(q1.front());
        q1.pop();
        q.push(q2.front());
        q2.pop();
    }
    return;
}

int main()
{
    int n;
    cin >> n;
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        int ele;
        cin >> ele;
        q.push(ele);
    }
    interleave(q, n);

    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }

    return 0;
}