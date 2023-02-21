//User function template for C++

/*
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/
class Solution{
    public:
    //Function to find the height of a binary tree.
    int height(struct Node* node){
        // code here 
        if(node==NULL) return 0;
        
        int left=height(node->left);    //left subtree ki height dega
        int right=height(node->right);  // right subtree ki height dega
        
        return max(left,right)+1;
    }
};