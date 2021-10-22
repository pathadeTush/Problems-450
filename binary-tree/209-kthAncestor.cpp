/*
        1
       / \
      4   2
    /  \   \
   3   7    6
  /
 8
 
*/

bool kth_Ancestor(Node *root, int &k, int node, int &ans)
{
  if (!root)
    return false;

  if (root->data == node || kth_Ancestor(root->left, k, node, ans) || kth_Ancestor(root->right, k, node, ans))
  {
    if (k == 0 && ans == -1)
    {
      ans = root->data;
      return true;
    }

    k--;

    return true;
  }
  return false;
}

int kthAncestor(Node *root, int k, int node)
{
  if (!root || k == 0)
    return -1;
  int ans = -1;
  kth_Ancestor(root, k, node, ans);
  return ans;
}