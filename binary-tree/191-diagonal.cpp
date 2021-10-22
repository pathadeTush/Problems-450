
/* 

  steps:

  add element to ans and go to right till right not null. meanwhile for each node add its left child to queue if exist.

now pop element from queue and perfom above procedure.

*/

vector<int> diagonal(Node *root)
{
    vector<int> ans;
    if (!root)
        return ans;

    queue<Node *> q;

    q.push(root);
    while (!q.empty())
    {
        Node *curr = q.front();
        q.pop();

        while (curr)
        {
            ans.push_back(curr->data);
            if (curr->left)
                q.push(curr->left);

            curr = curr->right;
        }
    }
    return ans;
}