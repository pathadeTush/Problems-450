bool isSumTree(Node *root)
{
    if (!root)
        return true;

    int sum = 0;
    if (root->left)
        sum += root->left->data;
    if (root->right)
        sum += root->right->data;

    isSumTree(root->left);
    isSumTree(root->right);

    if (root->left)
        sum += root->left->data;
    if (root->right)
        sum += root->right->data;

    // leaf node are always follow sum tree property (given)
    if (!root->left && !root->right)
    {
        root->data = 0;
        return true;
    }
    return (sum == root->data);
}
