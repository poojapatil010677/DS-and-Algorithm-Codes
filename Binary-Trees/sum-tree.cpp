/*

Write a function that returns true if the given Binary Tree of size N is SumTree 
else return false. A SumTree is a Binary Tree in which value of each node x is 
equal to sum of nodes present in its left subtree and right subtree . An empty 
tree is SumTree and sum of an empty tree can be considered as 0. A leaf node is 
also considered as SumTree.

Input:
2
3 1 2
10 20 30 10 10

Output:
1
0

*/


struct Node
{
    int data;
    Node* left, * right;
}; 

int sumUtil(Node* root)
{
    if(root==NULL) return 0;
    else if(root->left==NULL && root->right==NULL)
        return root->data;
    return sumUtil(root->left)+sumUtil(root->right)+root->data;
}

bool isSumTree(Node* root)
{
     if(root==NULL) return true;
     int res = sumUtil(root);
     if((res/2) == root->data) return true;
     return false;
}
