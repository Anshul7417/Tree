#include <bits/stdc++.h> 
/*
    Following is the Binary Tree node structure:

    class BinaryTreeNode {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };
*/

bool searchInBST(BinaryTreeNode<int> *root, int x) {
    // Write your code here.
    if(x==root->data) return 1;

    while(root!=NULL){
    if(x>root->data) root=root->right;
    else if (x==root->data) return 1;
    else root=root->left;}



    return 0;
}