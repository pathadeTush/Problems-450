void inorder(Node *root, vector<int> &v)
{
    if (!root)
        return;

    inorder(root->left, v);
    v.push_back(root->data);
    inorder(root->right, v);

    return;
}
int KthSmallestElement(Node *root, int K)
{
    vector<int> arr;
    inorder(root, arr);

    return (K <= arr.size()) ? arr[K - 1] : -1;
}

// OR
// space complexity O(1)
int KthSmallestElement(Node *root, int &K)
{
    if (!root)
        return -1;
    int res = KthSmallestElement(root->left, K);
    if (res != -1)
        return res;
    K--;
    if (!K)
        return root->data;
    res = KthSmallestElement(root->right, K);
    if (res != -1)
        return res;
}