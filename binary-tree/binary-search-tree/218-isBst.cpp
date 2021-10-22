
int isBSTUtil(node *node, int min, int max);

/* Returns true if the given 
tree is a binary search tree 
(efficient version). */
int isBST(node *node)
{
    return (isBSTUtil(node, INT_MIN, INT_MAX));
}

/* Returns true if the given
tree is a BST and its values
are >= min and <= max. */
int isBSTUtil(node *node, int min, int max)
{
    /* an empty tree is BST */
    if (node == NULL)
        return 1;

    /* false if this node violates
    the min/max constraint */
    if (node->data < min || node->data > max)
        return 0;

    /* otherwise check the subtrees recursively, 
    tightening the min or max constraint */
    return isBSTUtil(node->left, min, node->data - 1) && // Allow only distinct values
           isBSTUtil(node->right, node->data + 1, max);  // Allow only distinct values
}
