//K distance from root

/*
Given a Binary Tree of size N and an integer K. Print all nodes that are at 
distance k from root (root is considered at distance 0 from itself). 
Nodes should be printed from left to right. If k is more that height of tree, 
nothing should be printed
*/

/* A binary tree node has data, pointer to left child
   and a pointer to right child /
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */

void printNode(struct Node* root, int k, int c)
{
    if(root!=NULL)
    {
        if(c==k)
        {
            printf("%d ",root->data);
            return;
        }
        printNode(root->left,k,c+1);
        printNode(root->right,k,c+1);
    }
}

// function should print the nodes at k distance from root
void printKdistance(struct Node *root, int k)
{
  // Your code here
  if(root!=NULL)
  {
      printNode(root,k,0);
  }
}
