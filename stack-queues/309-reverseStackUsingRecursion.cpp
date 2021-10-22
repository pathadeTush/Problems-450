#include <bits/stdc++.h>
using namespace std;

void insertAtBottom(stack<int> &s, int bottomEle)
{
    if (s.empty())
    {
        s.push(bottomEle);
        return;
    }

    int ele = s.top();
    s.pop();
    insertAtBottom(s, bottomEle);
    s.push(ele);

    return;
}

void reverseStack(stack <int> &s){
    if(s.empty())
        return;

    int ele = s.top();
    s.pop();
    reverseStack(s);
    insertAtBottom(s, ele);

    return;
}

int main()
{
    int n;
    cin >> n;
    stack<int> s;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        s.push(x);
    }

    reverseStack(s);
    for (int i = 0; i < n; i++)
    {
        cout << s.top() << " ";
        s.pop();
    }

    return 0;
}