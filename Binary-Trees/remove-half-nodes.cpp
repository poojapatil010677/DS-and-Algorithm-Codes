/*

Problem Description

Given a binary tree A with N nodes.

You have to remove all the half nodes and return the final binary tree.

NOTE:

Half nodes are nodes which have only one child.
Leaves should not be touched as they have both children as NULL.

*/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 TreeNode* helper(TreeNode* root)
 {
    if(root->left==NULL && root->right==NULL)
        return root;
    if(root->left!=NULL && root->right!=NULL)
    {
        root->left = helper(root->left);
        root->right = helper(root->right);
        return root;
    }
    else if(root->left==NULL)
    {
        root->right = helper(root->right);
        return root->right;
    }
    root->left = helper(root->left);
    return root->left;
        
 }
 
TreeNode* Solution::solve(TreeNode* A) {
    if(A==NULL) return NULL;
    return helper(A);
    
}

