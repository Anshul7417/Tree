
/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution{
    public:
    //  use loop not map
    void createMapping(int in[], map<int,int> &nodeToIndex,int n){
        for(int i=0;i<n;i++){
            nodeToIndex[in[i]]=i;
        }
    }
    
    Node* solve(int in[],int pre[], int &index, int inorderStart, int inorderEnd, int n ,map<int,int> & nodeToIndex){
        
        if(index>=n || inorderStart > inorderEnd){
            return NULL;
        }
        
        int element =pre[index++];
        
        Node* root = new Node(element);
        
        int position = nodeToIndex[element];
        
        
        root->left=solve(in,pre,index,inorderStart,position-1,n,nodeToIndex);
        
        root->right=solve(in,pre,index,position+1,inorderEnd,n,nodeToIndex);
        
        return root;
    }
    Node* buildTree(int in[],int pre[], int n)
    {
        // Code here
        int preOrderIndex=0;
        
        map<int,int> nodeToIndex;
        
        
        
        createMapping(in,nodeToIndex,n);
        
        Node* ans=solve(in,pre,preOrderIndex,0,n-1,n,nodeToIndex);
        
        return ans;
    }
};