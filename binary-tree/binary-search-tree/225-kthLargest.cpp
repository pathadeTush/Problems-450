void inorder(Node *root, vector<int> &v)
{
    if (!root)
        return;

    inorder(root->left, v);
    v.push_back(root->data);
    inorder(root->right, v);

    return;
}

int kthLargest(Node *root, int K)
{
    vector<int> arr;
    inorder(root, arr);

    return arr[arr.size() - K];
}