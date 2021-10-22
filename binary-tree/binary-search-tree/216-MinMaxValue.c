int minValue(Node* root)
{
    // Code here
    
    Node *p = root;
    while(p->left){
        p = p->left;
    }
    return p->data;
}

