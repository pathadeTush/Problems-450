void longestPathSum(Node *root, int level, int &longestPath, int pathSum, int &sum)
{
    if (!root)
        return;

    longestPathSum(root->left, level + 1, longestPath, pathSum + root->data, sum);
    longestPathSum(root->right, level + 1, longestPath, pathSum + root->data, sum);

    if (!root->left && !root->right)
    {
        if (longestPath < level)
        {
            sum = pathSum + root->data;
            longestPath = level;
        }
        else if (longestPath == level)
            sum = max(sum, pathSum + root->data);
    }

    return;
}

int sumOfLongRootToLeafPath(Node *root)
{
    int sum = 0, longestPath = 0;

    longestPathSum(root, 0, longestPath, 0, sum);

    return sum;
}