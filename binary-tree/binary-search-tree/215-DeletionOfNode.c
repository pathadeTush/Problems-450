struct TreeNode* deleteNode(struct TreeNode* root, int key){
    if(root == NULL)
        return NULL;
    
    struct TreeNode *p = root, *q = NULL;
    while(p){
        if(p->val == key)
            break;
        q = p;
        if(p->val > key)
            p = p->left;
        else
            p = p->right;
    }
    
    // if not found
    if(p == NULL)
        return root;
    
    // if leaf node
    if(!p->left && !p->right)
    {
        if(!q){
            root = NULL;
            free(p);
            return root;
        }
        if(q->val < key)
            q->right = NULL;
        else
            q->left = NULL;

        return root;
    }
    
    // if node having one left child
    if(p->left && !p->right){
        if(!q){
            root = p->left;
            free(p);
            return root;
        }
        if(q->val < key)
            q->right = p->left;
        else
            q->left = p->left;
        free(p);
        return root;
    }
    
    // if node having one  right child
    if(!p->left && p->right){
        if(!q){
            root = p->right;
            free(p);
            return root;
        }
        if(q->val < key)
            q->right = p->right;
        else
            q->left = p->right;
        free(p);
        return root;
    }
    
    // if node having two child
    
    if(p->left && p->right){
        if(!q){
            root = p->right;
            struct TreeNode *temp = p->right;
            while (1)
            {
                if (temp->left)
                    temp = temp->left;
                else
                    break;
            }
            temp->left = p->left;
            free(p);
            return root;
        }
        if (q->val < key)
        {
            // printf("side\n");
            q->right = p->left;
            struct TreeNode *temp = p->left;
            while (1)
                if (temp->right)
                    temp = temp->right;
                else
                    break;
            temp->right = p->right;
            free(p);
            return root;
        }
        else
        {
            // printf("!side\n");
            q->left = p->right;
            struct TreeNode *temp = p->right;
            while (1)
            {
                if (temp->left)
                    temp = temp->left;
                else
                    break;
            }
            temp->left = p->left;
            free(p);
            return root;
        }
    }
    
    return root;
}
