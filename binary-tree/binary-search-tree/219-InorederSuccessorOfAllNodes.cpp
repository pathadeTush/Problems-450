void populateNext(struct node *p)
{

    // Your code goes here

    static node *prev = nullptr;
    if (p == nullptr)
        return;

    populateNext(p->left);

    if (prev)
        prev->next = p;

    prev = p;

    populateNext(p->right);

    return;
}