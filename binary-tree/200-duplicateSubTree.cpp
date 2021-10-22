
// take one map and store root->data as key and left child data as a value
// in inner loop...
// if map[key] is already present then check for its left child with current left child
// if they are equal then subtree is present otherwise add that left child data pair also
// to that key's value  


bool dupSub(Node *root)
{
    if (!root)
        return false;

    map<int, vector<pair<int, int>>> m; // data and vector of pair of left right child data

    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        int levelSize = q.size();
        while (levelSize--)
        {
            Node *curr = q.front();
            int d = curr->data;
            pair<int, int> p;
            p.first = (curr->left) ? (curr->left->data) : -1;
            p.second = (curr->right) ? (curr->right->data) : -1;

            q.pop();
            if (m[d].empty())
                m[d].push_back(p);
            else
            {
                for (auto i : m[d])
                {
                    if ((i.first != -1 && i.second != -1) && i.first == p.first && i.second == p.second)
                        return true;
                }
                m[d].push_back(p);
            }

            if (curr->left)
                q.push(curr->left);
            if (curr->right)
                q.push(curr->right);
        }
    }
    return false;
}