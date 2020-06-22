/*

Delete Node in BST

Given a root node reference of a BST and a key, delete the node with the given key in the BST. Return the root node reference (possibly updated) of the BST.

Basically, the deletion can be divided into two stages:

1. Search for a node to remove.
2. If the node is found, delete the node.

Note: Time complexity should be O(height of tree).

*/

class Solution {
public:
    
    TreeNode* getMinNode(TreeNode* root)
    {
        TreeNode* curr = root;
        while(curr!=NULL && curr->left!=NULL)
            curr = curr->left;
        return curr;
    }
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        
        if(root==NULL) return NULL;
        
        else if(key>root->val)
            root->right = deleteNode(root->right,key);
        
        else if(key<root->val)
            root->left = deleteNode(root->left,key);
        
        else
        {
            if(root->left==NULL)
                return root->right;
            
            else if(root->right==NULL)
                return root->left;
            
            TreeNode* temp = getMinNode(root->right);
            root->val = temp->val;
            root->right = deleteNode(root->right,temp->val);
        }
        return root;
    }
};
