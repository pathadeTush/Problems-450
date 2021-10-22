bool checkLevel(Node *root, int level, int &depth)
{
    if (!root)
        return true;

    if (!checkLevel(root->left, level + 1, depth) ||
        !checkLevel(root->right, level + 1, depth))
        return false;

    // if leaf node
    if (!root->left && !root->right)
    {
        if (depth && depth == level)
            return true;
        else if (depth == 0)
        {
            depth = level;
            return true;
        }
        else
            return false;
    }
    else
        return true;
}

bool check(Node *root)
{
    int depth = 0;
    return checkLevel(root, 0, depth);
}