void printVector(const vector<int> &v, int i)
{
    for (int j = i; j < v.size(); j++)
        cout << v[j] << " ";
    cout << endl;
}

// This function prints all paths that have sum k
void printKPathUtil(Node *root, vector<int> &path, int k)
{
    // empty node
    if (!root)
        return;

    // add current node to the path
    path.push_back(root->data);

    // check if there's any k sum path
    // in the left sub-tree.
    printKPathUtil(root->left, path, k);

    // check if there's any k sum path
    // in the right sub-tree.
    printKPathUtil(root->right, path, k);

    // check if there's any k sum path that
    // terminates at this node
    // Traverse the entire path as
    // there can be negative elements too
    int f = 0;
    for (int j = path.size() - 1; j >= 0; j--)
    {
        f += path[j];

        // If path sum is k, print the path
        if (f == k)
            printVector(path, j);
    }

    // Remove the current element from the path
    path.pop_back();
}
