/*
     start traversing left subtree and right subtree. If node is found with data as n1 or n2
     then return that node every time onwards else return null (if no such node is found till now).

     if we found first node with its l and r are non null then this node is LCA (our ans). return that node.
*/

Node *lca(Node *root, int n1, int n2)
{
    if (!root)
        return nullptr;

    if (root->data == n1 || root->data == n2)
        return root;

    Node *l = lca(root->left, n1, n2);
    Node *r = lca(root->right, n1, n2);

    if (l && r)
        return root;

    return (l) ? l : r; // return non null value
}
