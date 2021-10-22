vector<int> arr;

void preOrder(Node *root)
{
    if (root == nullptr)
        return;

    arr.push_back(root->data);
    preOrder(root->left);
    preOrder(root->right);
}

void inorder(Node *root, int *i)
{
    if (root == nullptr)
        return;

    inorder(root->left, i);
    root->data = arr[(*i)++];
    inorder(root->right, i);
}

// The given root is the root of the Binary Tree
// Return the root of the generated BST
Node *binaryTreeToBST(Node *root)
{
    //Your code goes here
    if (root == nullptr)
        return root;
    preOrder(root);
    sort(arr.begin(), arr.end());

    int i = 0;
    inorder(root, &i);

    return root;
}