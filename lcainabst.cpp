TreeNode<int>* LCAinaBST(TreeNode<int>* root, TreeNode<int>* P, TreeNode<int>* Q)
{
	// Write your code here
    if(root==NULL) return root;
    if(P->data<root->data&&Q->data<root->data) return LCAinaBST(root->left,P,Q);
    if(P->data>root->data&&Q->data>root->data)  return LCAinaBST(root->right,P,Q);
    return root;
}




//non recursive
TreeNode<int>* LCAinaBST(TreeNode<int>* root, TreeNode<int>* P, TreeNode<int>* Q)
{
	// Write your code here
        while (root != NULL) {
          if (root->data < P->data && root->data < Q->data)
            root = root->right;
          else if (root->data > P->data && root->data > Q->data)
            root = root->left;
          else
            return root;
        }
}
