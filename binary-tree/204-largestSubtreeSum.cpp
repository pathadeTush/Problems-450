/*
Input :       1
            /   \
           2      3
          / \    / \
         4   5  6   7


     

*/

int sum(Node *root, int &maxSum)
{
    if (!root)
        return 0;

    int l = sum(root->left);
    int r = sum(root->right);
    int x = root->data;

    maxSum = max(maxSum, l + r + x);

    return l + r + x;
}