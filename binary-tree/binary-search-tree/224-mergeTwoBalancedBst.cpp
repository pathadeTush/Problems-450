
void inorder(Node *root, vector<int> &v)
{
    if (!root)
        return;

    inorder(root->left, v);
    v.push_back(root->data);
    inorder(root->right, v);

    return;
}

vector<int> merge(Node *root1, Node *root2)
{
    vector<int> arr1;
    vector<int> arr2;

    inorder(root1, arr1); // store tree1 elements in arr1 in sorted form 
    inorder(root2, arr2); // store tree2 elements in arr2 in sorted form

    vector<int> res;

    // apply mergeSort merging concept
    // OR take new array and store arr1 and arr2 elements in it in sorted form

    int i = 0, j = 0;

    for (; i < arr1.size() && j < arr2.size();)
    {
        if (arr1[i] > arr2[j])
        {
            res.push_back(arr2[j]);
            j++;
        }
        else if (arr1[i] < arr2[j])
        {
            res.push_back(arr1[i]);
            i++;
        }
        else
        {
            res.push_back(arr1[i]);
            res.push_back(arr1[i]);
            i++;
            j++;
        }
    }

    while (i < arr1.size())
    {
        res.push_back(arr1[i++]);
    }
    while (j < arr2.size())
    {
        res.push_back(arr2[j++]);
    }

    return res;
}