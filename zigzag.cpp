//User function Template for C++
/*Structure of the node of the binary tree is as
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
    //Function to store the zig zag order traversal of tree in a list.
    vector <int> zigZagTraversal(Node* root)
    {
    	// Code here
    	 vector <int> result;
    	 if(root==NULL) return result;
    	 
    	 queue<Node*> q;
    	 q.push(root);
    	 
    	 bool lefttoright=true;
    	 
    	 while(!q.empty()){
    	     int size=q.size();
    	     vector<int> ans(size);
    	     
    	     for(int i=0;i<size;i++){
    	         Node* frontNode=q.front();
    	         q.pop();
    	         
    	         int index = lefttoright?i:size-i-1;
    	         ans[index]=frontNode->data;
    	         
    	         if(frontNode->left){ q.push(frontNode->left);}
    	         
    	         if(frontNode->right){ q.push(frontNode->right);}
    	     }
    	     
    	     lefttoright=!lefttoright;
    	     for(auto i: ans){
    	         result.push_back(i);
    	     }
    	 }
    	 
    	 return result;
    }
};