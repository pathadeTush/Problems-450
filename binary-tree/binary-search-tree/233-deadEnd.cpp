/*
              8
            /   \ 
           7     10
         /      /   \
        2      9     13
*/

bool isDeadNode(Node *root, int mn, int mx)
{
    if (!root)
        return false;

    // 0 becoz all num > 0
    if ((root->data - 1 == mn || root->data - 1 == 0) && (root->data + 1 == mx))
        return true;

    else
        return (isDeadNode(root->left, mn, root->data) || isDeadNode(root->right, root->data, mx));
}

/*You are required to complete below method */
bool isDeadEnd(Node *root)
{
    return isDeadNode(root, INT_MIN, INT_MAX);
}
/*

                (8, min, max)
            (7, min, 8)      (10, 8, max)
        (2, min, 7)      (9, 8, 10)
    

*/
