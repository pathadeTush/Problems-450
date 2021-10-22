void leftTree(Node *root, vector<int> &ans)
{
    if (!root)
        return;

    if (root->left)
    {
        ans.push_back(root->data);
        leftTree(root->left, ans);
    }
    else if (root->right)
    {
        ans.push_back(root->data);
        leftTree(root->right, ans);
    }
    return;
}

void leafNodes(Node *root, vector<int> &ans)
{
    if (!root)
        return;

    leafNodes(root->left, ans);
    if (!root->left && !root->right)
        ans.push_back(root->data);

    leafNodes(root->right, ans);

    return;
}

void rightTree(Node *root, vector<int> &ans)
{
    if (!root)
        return;

    if (root->right)
    {
        rightTree(root->right, ans);
        ans.push_back(root->data);
    }
    else if (root->left)
    {
        rightTree(root->left, ans);
        ans.push_back(root->data);
    }
    return;
}

vector<int> printBoundary(Node *root)
{
    vector<int> ans;

    if (!root)
        return ans;

    ans.push_back(root->data);

    leftTree(root->left, ans);
    leafNodes(root, ans);
    rightTree(root->right, ans);

    return ans;
}