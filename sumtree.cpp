/*  Tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

// Should return true if tree is Sum Tree, else false
class Solution
{
    public:
    pair<bool,int> sumfast(Node* root){
        if (root==NULL){
            pair<bool,int>p=make_pair(true,0);
            return p;
        }
        
        if(root->left==NULL and root->right==NULL){
            pair<bool,int>p=make_pair(true,root->data);
            return p;
        }
        
        pair<bool,int>leftans=sumfast(root->left);
        pair<bool,int>rightans=sumfast(root->right);
        
        bool left=leftans.first;
        bool right=rightans.first;
        
        bool condn = root->data==leftans.second+rightans.second;
        
        pair<bool,int>ans;
        
        if(left and right and condn){
            ans.first=true;
            ans.second=2*root->data;
        }else{
            ans.first=false;
        }
        
        
        return ans;
    }
    bool isSumTree(Node* root)
    {
         // Your code here
         return sumfast(root).first;
    }
};