// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class SortedStack
{
public:
    stack<int> s;
    void sort();
};

void printStack(stack<int> s)
{
    while (!s.empty())
    {
        printf("%d ", s.top());
        s.pop();
    }
    printf("\n");
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        SortedStack *ss = new SortedStack();
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            int k;
            cin >> k;
            ss->s.push(k);
        }
        ss->sort();
        printStack(ss->s);
    }
} // } Driver Code Ends

/*The structure of the class is
class SortedStack{
public:
	stack<int> s;
	void sort();
};
*/

void adjustPosition(stack<int> &s, int x)
{
    if (s.empty() or s.top() <= x)
    {
        s.push(x);
        return;
    }

    int ele = s.top();
    s.pop();
    adjustPosition(s, x);
    s.push(ele);

    return;
}

void sortStack(stack<int> &s)
{
    if (s.empty())
        return;

    int ele = s.top();
    s.pop();
    sortStack(s);
    adjustPosition(s, ele);

    return;
}

/* The below method sorts the stack s 
you are required to complete the below method */
void SortedStack ::sort()
{
    sortStack(s);
    return;
}