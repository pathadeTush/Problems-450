
void inorder(Node *root, vector<int> &v)
{
    if (!root)
        return;

    inorder(root->left, v);
    v.push_back(root->data);
    inorder(root->right, v);

    return;
}

float findMedian(struct Node *root)
{
    vector<int> arr;
    inorder(root, arr);

    float median;
    if (arr.size() % 2 != 0)
        median = arr[arr.size() / 2];
    else
        median = (arr[arr.size() / 2] + arr[arr.size() / 2 - 1]) / 2.0;

    return median;
}