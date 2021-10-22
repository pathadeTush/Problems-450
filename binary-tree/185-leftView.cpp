/*

In left view, we can see first element of a level only for each level. So add it to the ans.

levelSize is total no. of element in a particular level



O(n)
*/
vector<int> leftView(Node *root)
{

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
            if (curr->left)
                q.push(curr->left);
            if (curr->right)
                q.push(curr->right);

            q.pop();
        }
    }

    return ans;
}
