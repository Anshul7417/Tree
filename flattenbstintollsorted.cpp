 /*
    Time Complexity : O(N)
    Space Complexity : O(N)

    Where 'N' is the total number of nodes in the given BST.
*/

void inorder(TreeNode<int> *root, vector<int> &inorderArray)
{
    if (root == NULL)
    {
        return;
    }
    
    // Recur for left sub-tree
    inorder(root->left, inorderArray);

    // Add current node data to array
    inorderArray.push_back(root->data);

    // Recur for right sub-tree
    inorder(root->right, inorderArray);
}

TreeNode<int>* flatten(TreeNode<int>* root)
{

    if (root == NULL)
    {
        return root;
    }
    
    // Array to store inorder traversal
    vector<int> inorderArray;
    
    inorder(root, inorderArray);

    // Create a pointer called newRoot, and store the first value of the array in it.
    TreeNode<int> *newRoot = new TreeNode<int>(inorderArray[0]);

    // Create a pointer called curr and store the newRoot in it.
    TreeNode<int> *curr = newRoot;

    for (int i = 1; i < inorderArray.size(); i++)
    {

        // Create a new node.
        TreeNode<int> *temp = new TreeNode<int>(inorderArray[i]);

        // Make the left child of curr as NULL and right child as the temp. And make curr = temp.
        curr->left = NULL;
        curr->right = temp;
        curr = temp;
    }

    // Make both the left and the right child of the last node as NULL.
    curr->left = NULL;
    curr->right = NULL;

    return newRoot;
}
 