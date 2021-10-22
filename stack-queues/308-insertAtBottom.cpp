#include <bits/stdc++.h>
using namespace std;

void insertAtBottom (stack <int> &s, int bottomEle){
    if(s.size() == 0){
        s.push(bottomEle);
        return;
    }

    int temp = s.top();
    s.pop();
    insertAtBottom(s, bottomEle);
    s.push(temp);

    return;
}

int main()
{
    int n;
    cin >> n;
    stack<int> s;

    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        s.push(x);
    }

    int bottomEle;
    cin >> bottomEle;

    insertAtBottom(s, bottomEle);

    for (int i = 0; i <= n; i++)
    {
        cout << s.top() << " ";
        s.pop();
    }

    return 0;
}