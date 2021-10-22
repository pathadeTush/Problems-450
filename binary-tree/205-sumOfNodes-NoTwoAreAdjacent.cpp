/*
              1
            /   \
           2      3
          /      / \
         1      4   5

Approach:

case 1:if current node is included in ans then
        we have 4 choice to take next element. 
          i.   node->left->left
          ii.  node->left->right
          iii. node->right->left
          iv.  node->right->right

case 2:if current node is not included in ans then
        we have 2 choice to take next element.
          i.   node->left
          ii.  node->right       

finally return max(case1 ans, case2 ans)

Also store the max ans of individual node. So that it can be used later in recursion if recursion goes to same node again. In this way it will reduced time complexity. Else time complexity would be 2^n.
     
*/

unordered_map<Node *, int> dp; // map to store result for each node

int func(Node *root)
{
    if (!root)
        return 0;

    if (dp[root])
        return dp[root];

    // case 1
    int included = root->data;
    if (root->left)
    {
        included += func(root->left->left);
        included += func(root->left->right);
    }
    if (root->right)
    {
        included += func(root->right->left);
        included += func(root->right->right);
    }

    // case2
    int excluded = func(root->left) + func(root->right);

    dp[root] = max(included, excluded);

    return dp[root];
}