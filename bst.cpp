#include<iostream>
#include<queue>

using namespace std;

class Node{


    public:
        int data;
        Node* left;
        Node* right;


        Node(int d){
            this->data=d;
            this->left=NULL;
            this->right=NULL;
        }
};


void levelOrdertraversal(Node* root){
 if (root == NULL)
        return;
 
    // Create an empty queue for level order traversal
    queue<Node*> q;
 
    // Enqueue Root and initialize height
    q.push(root);
 
    while (q.empty() == false) {
        // Print front of queue and remove it from queue
        Node* node = q.front();
        cout << node->data << " ";
        q.pop();
 
        /* Enqueue left child */
        if (node->left != NULL)
            q.push(node->left);
 
        /*Enqueue right child */
        if (node->right != NULL)
            q.push(node->right);
    }
}


Node* insertIntoBST(Node*  root,int d){
    if(root==NULL){
        root=new Node(d);
        return root;
    }

    if(d>root->data){
        root->right=insertIntoBST(root->right, d);
    }else{
        root->left=insertIntoBST(root->left, d);
    }

    return root;
}
void takeinput(Node* &root){
    int data;
    cin>>data;

    while(data!=-1){
        insertIntoBST(root,data);
        cin>>data;

    }
}

int main()
{       

    Node* root  =NULL;

    cout<<"Enter data to create BST";
    takeinput(root);


    levelOrdertraversal(root);
    
    
    return 0;
}