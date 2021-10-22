/*
first add left right data to current node
then call recursively for left right node
after which left and right node will have sum of their left and right node
so again add left right data to current node 

*/

void toSumTree(Node *root)
{
    if (!root)
        return;

    root->data = 0;
    if (root->left)
        root->data += root->left->data;
    if (root->right)
        root->data += root->right->data;

    toSumTree(root->left);
    toSumTree(root->right);

    if (root->left)
        root->data += root->left->data;
    if (root->right)
        root->data += root->right->data;

    return;
}


// another code

int toSumTree(Node *root){
    if(!root)
        return 0;
    int a = toSumTree(root->left);
    int b = toSumTree(root->right);
    int x = root->data;
    root->data = a + b;

    return a + b + x;
}
/*

int toSumTree(Node *root){
    if(!root)
        return 0;
    int a = toSumTree(root->left);
    int b = toSumTree(root->right);
    int x = root->data;
    root->data = a + b;
    
    sum = sum + a-b;

    return a + b + x;
}*/
