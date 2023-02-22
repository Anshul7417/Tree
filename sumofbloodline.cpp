//User function Template for C++

/*
structure of the node of the binary tree is as
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/
class Solution
{
public:

    void solve(Node* root,int sum,int &maxsum,int len,int &maxlen){
        if(root==NULL){
            if(len>maxlen){
                maxsum=sum;
                maxlen=len;
            }else if(len==maxlen){
                maxsum=max(maxsum,sum);
            }
            
            return;
        }
        
        sum=sum+root->data;
        
        solve(root->left,sum,maxsum,len+1,maxlen);
        
        solve(root->right,sum,maxsum,len+1,maxlen);

    }
    
    int sumOfLongRootToLeafPath(Node *root)
    {
        //code here
        int len=0;
        int maxlen=0;
        
        int sum=0;
        int maxsum=INT_MIN;
        
        
        solve(root,sum,maxsum,len,maxlen);
        
        return maxsum;
        
    }
};