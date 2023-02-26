

/*Structure of the Node of the BST is as
struct Node
{
	int data;
	Node* left, *right;
};
*/
// Your are required to complete this function
// function should return root of the modified BST

void inorder(Node * root,vector<int>&inorderarr){
    if (root==NULL) return;
    
    inorder(root->left,inorderarr);
    
    inorderarr.push_back(root->data);
    
    inorder(root->right,inorderarr);
}

Node * inordertobst(int s, int e, vector<int>&inorderarr){
    if(s>e) return NULL;
    
    int mid= (s+e)/2;
    
    Node* root = new Node(inorderarr[mid]);
    
    root->left=inordertobst(s,mid-1,inorderarr);
    
    root->right=inordertobst(mid+1,e,inorderarr);
    
    return root;
}

Node* buildBalancedTree(Node* root)
{
	
	vector<int> inorderarr;
	
	inorder(root,inorderarr);
	
	return inordertobst(0,inorderarr.size()-1,inorderarr);
    
}