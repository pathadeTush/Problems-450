#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};
/*

 Do level Order traversal but add right child first then left child. You will get  

        1
    2       3
4      56       7

levelOrder : 1 2 3 4 5 6 7

reverseLevelOrder : 4 5 6 7 2 3 1

queue if we add right child first : 1 3 2 7 6 5 4

so our ans is just reversed of above

O(n)
*/

vector<int> reverseLevelOrder(Node *root)
{

    vector<int> ans;
    if (!root)
        return ans;
    queue<Node *> q;

    q.push(root);

    while (!q.empty())
    {
        Node *curr = q.front();
        ans.push_back(curr->data);
        q.pop();
        if (curr->right)
            q.push(curr->right);
        if (curr->left)
            q.push(curr->left);
    }

    reverse(ans.begin(), ans.end());

    return ans;
}
