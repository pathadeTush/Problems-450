/*

swap lsb and rsb recursively


O(n)
*/

void mirror(Node *root)
{
    if (!root)
        return;

    mirror(root->left);
    mirror(root->right);

    swap(root->left, root->right);

    return;
}