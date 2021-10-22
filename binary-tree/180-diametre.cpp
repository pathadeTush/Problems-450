/* 
Start finding distance between two leaf nodes from left subtree. dist = height(lsb)+height(rsb)+1(for root)

then go upward for and update dist if it is greator than prev.

O(n)
*/


int Diameter;
int height(struct Node *root)
{

    if (!root)
        return 0;
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    Diameter = max(Diameter, (leftHeight + rightHeight + 1));

    return (1 + max(leftHeight, rightHeight));
}

int diameter(Node *root)
{
    // Your code here

    Diameter = INT_MIN;
    height(root);

    return Diameter;
}