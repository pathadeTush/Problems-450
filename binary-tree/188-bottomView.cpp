
/*

perform levelOrder traversal

            1
        2       3
    4      5 6      7
    
ans = 4 6 7

*/

vector<int> bottomView(Node *root)
{

    map<int, int> hdData;       // hd (Key), Data(Value) map
    queue<pair<Node *, int>> q; // node and hd

    q.push({root, 0});

    while (!q.empty())
    {
        Node *curr = q.front().first;
        int hd = q.front().second;
        q.pop();

        hdData[hd] = curr->data;

        if (curr->left)
            q.push({curr->left, hd - 1});
        if (curr->right)
            q.push({curr->right, hd + 1});
    }

    vector<int> ans;
    for (auto i : hdData)
    {
        ans.push_back(i.second);
    }

    return ans;
}