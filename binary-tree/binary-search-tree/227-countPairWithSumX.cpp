void inorder(Node *root, vector<int> &v)
{
    if (!root)
        return;

    inorder(root->left, v);
    v.push_back(root->data);
    inorder(root->right, v);

    return;
}

// You are required to complete this function
int countPairs(Node *root1, Node *root2, int x)
{
    vector<int> arr1;
    vector<int> arr2;
    inorder(root1, arr1);
    inorder(root2, arr2);

    int count = 0;

    for (auto i : arr1)
    {
        for (auto j : arr2)
            if (i + j == x)
                count++;
    }

    return count;
}