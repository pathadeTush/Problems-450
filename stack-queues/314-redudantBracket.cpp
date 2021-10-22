#include <bits/stdc++.h>
using namespace std;

bool isNum(char ch){
    if(ch != ')' || ch != '(' || ch != '+' || ch != '-' || ch != '*' || ch != '/')
        return true;
    return false;
}

bool isRedundantBracket(string s)
{
    stack<char> st;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] != ')')
            st.push(s[i]);
        else
        {
            if (st.top() == '(')
                return true;
                // if a number is surrounded by bracket
            else if (isNum(st.top())){
                char temp = st.top();
                st.pop();
                if(st.top() == '(')
                    return true;
                else
                    st.push(temp);
            }
            if(st.top() != '(')
            {
                while (st.top() != '(')
                    st.pop();
                st.pop();
            }
        }
    }

    return false;
}

int main()
{
    string s;
    cin >> s;

    cout << isRedundantBracket(s) << endl;

    return 0;
}