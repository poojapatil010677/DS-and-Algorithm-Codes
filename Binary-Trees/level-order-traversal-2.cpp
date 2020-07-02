/*

Binary Tree Level Order Traversal Bottom Up

Given a binary tree, return the bottom-up level order traversal of its nodes' values.
(ie, from left to right, level by level from leaf to root).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its bottom-up level order traversal as:
[
  [15,7],
  [9,20],
  [3]
]

*/

class Solution {
public:
    
    int height(TreeNode* root)
    {
        if(root==NULL) return 0;
        else
        {
            int l = height(root->left);
            int r = height(root->right);
            if(l>r) return (l+1);
            return (r+1);
        }
    }
    
    void lot(TreeNode* root,int i,vector<int>& temp)
    {
        if(root==NULL) return;
        
        if(i==1)
            temp.push_back(root->val);
        else
        {
            lot(root->left,i-1,temp);
            lot(root->right,i-1,temp);
        }
    }
    
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        if(root==NULL) return res;
        int h = height(root);
        for(int i=h;i>0;i--)
        {
            vector<int> temp;
            lot(root,i,temp);
            res.push_back(temp);
        }
        return res;
    }
};
