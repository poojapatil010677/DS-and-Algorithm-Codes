/*

Maximum width of Binary Tree

Given a binary tree, write a function to get the maximum width of the given tree. 
The width of a tree is the maximum width among all levels. The binary tree has the 
same structure as a full binary tree, but some nodes are null.

The width of one level is defined as the length between the end-nodes (the leftmost 
and right most non-null nodes in the level, where the null nodes between the 
end-nodes are also counted into the length calculation.

Input: 

           1
         /   \
        3     2
       / \     \  
      5   3     9 

Output: 4
Explanation: The maximum width existing in the third level with the length 4 (5,3,null,9).
Example 2:

Input: 

          1
         /  
        3    
       / \       
      5   3     

Output: 2
Explanation: The maximum width existing in the third level with the length 2 (5,3).

*/

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;
        unsigned long long int ans = 0;
        queue<pair<TreeNode*,unsigned long long int>> q;
        q.push({root,1});
        while(!q.empty())
        {
            int cnt = q.size();
            unsigned long long int left = q.front().second,right;
            for(int i=0;i<cnt;i++)
            {
                TreeNode* n = q.front().first;
                right = q.front().second;
                q.pop();
                if(n->left!=NULL)
                    q.push({n->left,2*right});
                if(n->right!=NULL)
                    q.push({n->right,2*right+1});
                
            }
            
            ans = max(ans,(right-left+1));
        }
        return ans;
    }
};
