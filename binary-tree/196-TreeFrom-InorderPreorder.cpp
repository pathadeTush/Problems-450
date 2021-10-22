/* 
for each element in preorder search for its index in inorder. 
Now all elements to the left of that index are in left subtree of
that element and all elements to the right of that index are in right
subtree of that element

perform recursive operation on left subtree and right subtree
*/



int idx;
map<int, int> m; // key - inorder ele and value - index of ele in in array

Node *solve(int in[], int pre[], int lb, int ub)
{
    if (lb > ub)
        return nullptr;

    Node *res = new Node(pre[idx++]);

    if (lb == ub)
        return res;

    int mid = m[res->data]; // index of element in inorder array

    res->left = solve(in, pre, lb, mid - 1);
    res->right = solve(in, pre, mid + 1, ub);

    return res;
}

Node *buildTree(int in[], int pre[], int n)
{
    m.clear();
    idx = 0;

    for (int i = 0; i < n; i++)
        m[in[i]] = i;

    Node *root = solve(in, pre, 0, n - 1);

    return root;
}