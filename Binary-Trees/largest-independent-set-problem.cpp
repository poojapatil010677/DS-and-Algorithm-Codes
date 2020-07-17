/*

Largest Independent Set Problem

Given a Binary Tree of size N, find size of the Largest Independent Set(LIS) in it. 
A subset of all tree nodes is an independent set if there is no edge between any two 
nodes of the subset. Your task is to complete the function LISS(), which finds the 
size of the Largest Independent Set.

Input:
2
1 2 R 1 3 L
4
10 20 L 10 30 R 20 40 L 20 60 R
Output:
2
3

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
        
        pair<int,int> ans;
        ans.first = 1+l.second+r.second;
        ans.second = max(l.first,l.second) + max(r.first,r.second);
        return ans;
    }
}

int LISS(struct Node *root)
{
    if(root==NULL) return 0;
    pair<int,int> res = helper(root);
    return max(res.first,res.second);
}
