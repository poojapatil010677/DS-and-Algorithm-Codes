/*

Maximum sum of non-adjacent nodes

Given a binary tree with a value associated with each node, we need to choose a subset of these nodes such that sum of chosen nodes is maximum under a 
constraint that no two chosen node in subset should be directly connected that is, 
if we have taken a node in our sum then we can’t take its any children in consideration 
and vice versa.

Input:
2
11 1 2
1 2 3 4 N 5 6
Output:
11
16

*/

pair<int,int> helper(Node* root)
{
    if(root==NULL)
    {
        pair<int,int> p;
        p = make_pair(0,0);
        return p;
    }
    else
    {
        pair<int,int> l = helper(root->left);
        pair<int,int> r = helper(root->right);
        
        pair<int,int> res;
        res.first = root->data + l.second + r.second;
        res.second = max(l.first,l.second) + max(r.first,r.second);
        return res;
    }
}

int getMaxSum(Node *root) 
{
    if(root==NULL) return 0;
    pair<int,int> ans = helper(root);
    return max(ans.first,ans.second);
}
