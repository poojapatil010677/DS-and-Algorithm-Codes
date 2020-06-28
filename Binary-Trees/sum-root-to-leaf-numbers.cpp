/*

Sum Root to leaf numbers

Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

An example is the root-to-leaf path 1->2->3 which represents the number 123.

Find the total sum of all root-to-leaf numbers.

Input: [1,2,3]
    1
   / \
  2   3
Output: 25
Explanation:
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.
Therefore, sum = 12 + 13 = 25.

*/

void addSum(TreeNode* root,vector<int>& v,int curr)
    {
        if(root==NULL) return;
        curr = (curr*10)+root->val;
        if(root->left==NULL && root->right==NULL)
        {
            v.push_back(curr);
        }
        else
        {
            if(root->left!=NULL)
                addSum(root->left,v,curr);
            if(root->right!=NULL)
                addSum(root->right,v,curr);
        }
    }
    
    int sumNumbers(TreeNode* root) {
        
        if(root==NULL) return 0;
        
        vector<int> v;
        addSum(root,v,0);
        int s = 0;
        for(int i=0;i<v.size();i++)
        {
            s+=v[i];
        }
        return s;
    }
