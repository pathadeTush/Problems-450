void Count(Node *root, int l, int h, int &count)
{

    if (!root)
        return;
    if (root->data >= l && root->data <= h)
        count++;

    Count(root->left, l, h, count);
    Count(root->right, l, h, count);

    return;
}

int getCount(Node *root, int l, int h)
{
    int count = 0;
    Count(root, l, h, count);

    return count;
}