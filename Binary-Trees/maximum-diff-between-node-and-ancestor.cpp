/*

Given a Binary Tree, you need to find the maximum value which you can get by 
subtracting the value of node B from the value of node A, where A and B are 
two nodes of the binary tree and A is an ancestor of B. 

Example:
Input:
2
5 2 1
1 2 3 N N N 7
Output:
4
-1

*/

void maxUtil(Node* root,int* mmax, int mi,int ma)
{
    if(root==NULL) return;
    *mmax = max(mi-root->data,max(ma-root->data,*mmax));
    maxUtil(root->left,mmax,min(mi,root->data),max(root->data,ma));
    maxUtil(root->right,mmax,min(mi,root->data),max(root->data,ma));
}


int maxDiff(Node* root)
{
    if(root==NULL) return 0;
    int mmax = INT_MIN;
    maxUtil(root->left,&mmax,root->data,root->data);
    maxUtil(root->right,&mmax,root->data,root->data);
    return mmax;
}



