/*
First find lowest common ancestor (LCA)
then find dist of a and b w.r.to LCA
then dist betn a and b = dist(a) w.r.to LCA + dist(b) w.r.to LCA
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

    return (l) ? l : r;
}

void getDist(Node *root, int &aDist, int &bDist, int a, int b, int level)
{
    if (!root)
        return;

    if (aDist != -1 && bDist != -1)
        return;

    getDist(root->left, aDist, bDist, a, b, level + 1);
    getDist(root->right, aDist, bDist, a, b, level + 1);

    if (root->data == a)
        aDist = level;
    else if (root->data == b)
        bDist = level;

    return;
}

int findDist(Node *root, int a, int b)
{
    if (!root)
        return 0;
    Node *LCA = lca(root, a, b);

    int aDist = -1, bDist = -1;

    getDist(LCA, aDist, bDist, a, b, 0);

    return aDist + bDist;
}