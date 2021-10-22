
void inorder(Node *root, Node *&head, Node *&tail)
{
    if (!root)
        return;

    inorder(root->left, head, tail);

    Node *nn = (Node *)malloc(sizeof(Node));
    nn->data = root->data;
    nn->left = nn->right = nullptr;

    if (!head)
    {
        head = nn;
        tail = nn;
    }
    else
    {
        tail->right = nn; // right = next
        nn->left = tail;  // left = prev
        tail = nn;
    }

    inorder(root->right, head, tail);

    return;
}

Node *bToDLL(Node *root)
{
    // your code here
    Node *head = nullptr, *tail = nullptr;

    inorder(root, head, tail);

    return head;
}