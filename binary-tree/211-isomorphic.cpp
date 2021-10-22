/*
for each node check if its left and right chlld equal to of other node
if not check by swapping of any one of nodes child. if still not equal return false.
else return true
*/

bool isIsomorphic(Node *root1, Node *root2)
{
    if (!root1 && !root2)
        return true;
    if ((!root1 && root2) || (root1 && !root2))
        return false;
    if (root1->data != root2->data)
        return false;

    bool a = isIsomorphic(root1->left, root2->left) and isIsomorphic(root1->right, root2->right);
    bool b = isIsomorphic(root1->left, root2->right) and isIsomorphic(root1->right, root2->left);

    return a or b;
}