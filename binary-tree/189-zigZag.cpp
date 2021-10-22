
/* 
store element to the ans level wise and (store them in reverse order alternately)
*/
//Function to store the zig zag order traversal of tree in a list.
vector<int> zigZagTraversal(Node *root)
{
    // Code here
    vector<int> ans;

    queue<Node *> q;
    q.push(root);

    int flag = 0;

    while (!q.empty())
    {
        int levelSize = q.size();

        vector<int> temp;
        while (levelSize--)
        {
            Node *curr = q.front();
            q.pop();
            temp.push_back(curr->data);

            if (curr->left)
                q.push(curr->left);
            if (curr->right)
                q.push(curr->right);
        }
        if (flag)
            reverse(temp.begin(), temp.end());

        for (auto i : temp)
            ans.push_back(i);

        if (flag)
            flag = 0;
        else
            flag = 1;
    }

    return ans;
}