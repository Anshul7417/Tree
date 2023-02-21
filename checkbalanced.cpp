/* A binary tree node structure

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
    pair<int,int> balancedfast(Node * root){
        if(root==NULL){
            pair<bool,int>p=make_pair(true,0);
            return p;
        }
        
        pair<int,int>left=balancedfast(root->left);
        pair<int,int>right=balancedfast(root->right);
        
        bool leftans=left.first;
        bool rightans=right.first;
        
        bool diff=abs(left.second-right.second)<=1;
        
        pair<int,int> ans;
        
        ans.second=max(left.second,right.second)+1;
        if(diff and leftans and rightans) ans.first=true;
        else ans.first=false;
        
        return ans;
    }
    //Function to check whether a binary tree is balanced or not.
    bool isBalanced(Node *root)
    {
        //  Your Code here
        return balancedfast(root).first;
    }
};