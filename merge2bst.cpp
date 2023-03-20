#include <bits/stdc++.h> 
/*************************************************************
    
    Following is the Binary Tree node structure:

    class TreeNode{

        public :
            int data;
            TreeNode *left;
            TreeNode *right;

            TreeNode(int data) {
                this -> data = data;
                left = NULL;
                right = NULL;
            }

            ~TreeNode() {
            if (left){
            delete left;
            }

            if (right){
            delete right;
            }
        }   
    };

*************************************************************/
void inorder(TreeNode<int> *root, vector<int> & in){
    if(root==NULL) return;

    inorder(root->left,in);
    in.push_back(root->data);
    inorder(root->right,in);
}

vector<int> mergearray(vector<int> a, vector<int> b){
    int i=0, j=0, k=0;
    vector<int>ans(a.size()+b.size());
    while(i<a.size() && j<b.size()){
      if (a[i] > b[j]) {
        ans[k++] = b[j++];
      }else{
        ans[k++] = a[i++];
      }
    }


    while(i<a.size()){
        ans[k++] = a[i++];
    }


    while(j<b.size()){
        ans[k++] = b[j++];
    }


    return ans;
}


TreeNode<int>*  inordertobst(int s, int e, vector<int>&inorderarr){
    if(s>e) return NULL;
    
    int mid= (s+e)/2;
    
    TreeNode<int>*  root = new TreeNode<int>(inorderarr[mid]);
    
    root->left=inordertobst(s,mid-1,inorderarr);
    
    root->right=inordertobst(mid+1,e,inorderarr);
    
    return root;
}

TreeNode<int> *mergeBST(TreeNode<int> *root1, TreeNode<int> *root2){
    // Write your code here.
    vector<int> bst1, bst2;
    inorder(root1, bst1);
    inorder(root2, bst2);


    vector<int> mergearrays=mergearray(bst1,bst2);

    return inordertobst(0, mergearrays.size()-1, mergearrays);


    
}










void convertTosortedDLL(TreeNode<int> *root, TreeNode<int>* &head){
    if(root==NULL) 
        return;

    convertTosortedDLL(root->right, head);

    root->right=head;
    if(head!=NULL)
        head->left=root;

    head=root;


    convertTosortedDLL(root->left, head);


}


//optimal
TreeNode<int>* mergeLinkedList(TreeNode<int> *head1, TreeNode<int> *head2){
    TreeNode<int> *head=NULL;

    TreeNode<int> *tail=NULL;

    while(head1!=NULL && head2!=NULL){
        if(head1->data < head2->data){
            if(head==NULL){
                head=head1;
                tail=head1;
                head1=head1->right;
            }else{
                tail->right=head1;
                head1->left=tail;
                tail=head1;
                head1=head1->right;
            }
        }else{
            if(head==NULL){
                head=head2;
                tail=head2;
                head2=head2->right;
            }else{
                tail->right=head2;
                head2->left=tail;
                tail=head2;
                head2=head2->right;

            }
        }
    }


    while(head1!=NULL){
        tail->right = head1;
        head1->left=tail;
        tail=head1;
        head1=head1->right;
    }



    while(head2!=NULL){
        tail->right=head2;
        head2->left=tail;
        tail=head2;
        head2=head2->right;
    }
    



    return head;
}

int countNodes(TreeNode<int> *head){
    int cnt=0;
    TreeNode<int> *temp=head;
    while(temp!=NULL){
        cnt++;
        temp=temp->right;
    }

    return cnt;
}

TreeNode<int> *sortedLLtoBST(TreeNode<int> *&head, int n) {
    if(n<=0 || head==NULL){
        return NULL;
    }

    TreeNode<int> * left = sortedLLtoBST(head, n/2);

    TreeNode<int> * root= head;
    root->left=left;

    head=head->right;

    root->right=sortedLLtoBST(head, n-n/2-1);

    return root;
}





TreeNode<int> *mergeBST(TreeNode<int> *root1, TreeNode<int> *root2){

    //convert bst into sorted dll
        TreeNode<int> *head1=NULL;
        convertTosortedDLL(root1, head1);

        head1->left=NULL;


        TreeNode<int> *head2=NULL;
        convertTosortedDLL(root2, head2);

        head2->left=NULL;
    
    //merge sorted linked list

        TreeNode<int>* head= mergeLinkedList(head1, head2);

        return sortedLLtoBST(head, countNodes(head));

    
}