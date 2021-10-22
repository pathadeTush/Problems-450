/*

In right view, we can see last element of a level only for each level. So add it to the ans.

levelSize is total no. of element in a particular level

if we add right child first then we can get last element of a node at first in inner loop

O(n)

*/

vector<int> rightView(Node *root)
{
    // Your code here

    vector<int> ans;

    if (!root)
        return ans;

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        int levelSize = q.size();

        Node *curr = q.front();
        ans.push_back(curr->data);
        while (levelSize--)
        {
            Node *curr = q.front();
            if (curr->right)
                q.push(curr->right);
            if (curr->left)
                q.push(curr->left);

            q.pop();
        }
    }

    return ans;
}