/*

for each element it will be in topView if for a some horizonatal distance(hd) from root,
it has minimum depth among all who have same hd from root.

perform levelOrder traversal

            1
        2       3
    4      5 6      7
    
ans = 4 2 1 3 7

*/

class Solution
{
public:
    //Function to return a list of nodes visible from the top view
    //from left to right in Binary Tree.

    vector<int> topView(Node *root)
    {

        map<int, int> hdData;       // hd (Key), Data(Value) map
        queue<pair<Node *, int>> q; // node and hd

        q.push({root, 0});

        while (!q.empty())
        {
            Node *curr = q.front().first;
            int hd = q.front().second;
            q.pop();

            if (!hdData[hd])
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
};
