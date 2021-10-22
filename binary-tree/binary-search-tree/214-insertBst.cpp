Node *insert(Node *root, int key)
{
    Node *nn = (Node *)malloc(sizeof(Node));
    if (!nn)
        return root;

    nn->data = key;
    nn->left = nn->right = nullptr;

    Node *p = root, *q = nullptr;

    while (p)
    {
        q = p;
        if (p->data == key)
            return root;
        else if (p->data > key)
            p = p->left;
        else
            p = p->right;
    }

    if (!q)
        root = nn;

    else if (q->data > key)
        q->left = nn;
    else
        q->right = nn;

    return root;
}