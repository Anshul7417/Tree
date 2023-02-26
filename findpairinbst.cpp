/*Complete the function below
Node is as follows
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution{
  public:
    // root : the root Node of the given BST
    // target : the target sum
    
    void inorder(struct Node* root, vector<int>& inorderVal){
        if(root==NULL) return;
        
        inorder(root->left,inorderVal);
        
        inorderVal.push_back(root->data);
        
        inorder(root->right,inorderVal);
    }
    int isPairPresent(struct Node *root, int target)
    {
    //add code here.
    vector<int> inorderVal;
    
    inorder(root,inorderVal);
    
    int i=0,j=inorderVal.size()-1;
    
    while(i<j){
        if(inorderVal[i]+inorderVal[j]==target) return 1;
        else if(inorderVal[i]+inorderVal[j]>target) j--;
        else i++;
    }
    
    return 0;
    }
};