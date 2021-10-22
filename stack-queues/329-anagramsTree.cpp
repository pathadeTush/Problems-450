#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *left, *right;
    node(int d)
    {
        data = d;
        left = right = nullptr;
    }
};
/*

store all elements of each tree in separate vectore levelwise
Then sort both and return true if both are equal else return false;
*/
// Time Complexity: O(n)
bool areAnagrams(node *root1, node *root2)
{
    if (!root1 and !root2)
        return true;
    if ((!root1 and root2) or (root1 and !root2))
        return false;

    vector<int> v1, v2;
    queue<struct node *> q1, q2;
    q1.push(root1);
    q2.push(root2);

    v1.push_back(root1->data);
    v2.push_back(root2->data);

    while (!q1.empty() and !q2.empty())
    {
        int n1 = q1.size();
        int n2 = q2.size();

        if (n1 != n2)
            return false;

        while (n1--)
        {
            struct node *curr1 = q1.front();
            q1.pop();
            struct node *curr2 = q2.front();
            q2.pop();

            if (curr1->left)
            {
                v1.push_back(curr1->left->data);
                q1.push(curr1->left);
            }
            if (curr1->right)
            {
                v1.push_back(curr1->right->data);
                q1.push(curr1->right);
            }
            if (curr2->left)
            {
                v2.push_back(curr2->left->data);
                q2.push(curr2->left);
            }
            if (curr2->right)
            {
                v2.push_back(curr2->right->data);
                q2.push(curr2->right);
            }
        }
    }
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    if (v1 != v2)
        return false;
    return true;
}

int main()
{
    // Constructing both the trees.
    struct node *root1 = new node(1);
    root1->left = new node(3);
    root1->right = new node(2);
    root1->right->left = new node(5);
    root1->right->right = new node(4);

    struct node *root2 = new node(1);
    root2->left = new node(2);
    root2->right = new node(3);
    root2->left->left = new node(4);
    root2->left->right = new node(5);

    areAnagrams(root1, root2) ? cout << "Yes" : cout << "No";
    return 0;
}