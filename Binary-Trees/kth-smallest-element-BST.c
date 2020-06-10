/*

Kth smallest element in a BST

Given a binary search tree, write a function kthSmallest to find the kth 
smallest element in it.

*/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* ksmall(struct TreeNode* root,int* count, int k)
{
    if(root==NULL) return root;
    
    struct TreeNode* left = ksmall(root->left,count,k);
    if(left!=NULL) return left;
    
    *count = *count + 1;
    if(*count==k) return root;
    
    return ksmall(root->right,count,k);
}

int kthSmallest(struct TreeNode* root, int k){
    int count = 0;
    struct TreeNode* res = ksmall(root,&count,k);
    return res->val;
}
