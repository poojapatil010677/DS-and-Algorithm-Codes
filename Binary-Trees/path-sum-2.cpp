/*

Path sum 2

Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

Note: A leaf is a node with no children.

Given the below binary tree and sum = 22,

      5
     / \
    4   8
   /   / \
  11  13  4
 /  \    / \
7    2  5   1
Return:

[
   [5,4,11,2],
   [5,8,4,5]
]

*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    
    void findpath(TreeNode* root,int sum, vector<vector<int>> &paths, int c, vector<int> temp)
    {
        temp.push_back(root->val);
        c = c + root->val;
        if(root->left== NULL && root->right==NULL && sum==c)
        {
            paths.push_back(temp);
        }
        if(root->left!=NULL)
        {
            findpath(root->left,sum,paths,c,temp);
        }
        if(root->right!=NULL)
        {
            findpath(root->right,sum,paths,c,temp);
        }
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> paths;
        if(root==NULL) return paths;
        vector<int> temp;
        findpath(root,sum,paths,0,temp);
        return paths;
    }
};
