/*

Serialization is to store a tree in an array so that it can be later restored 
and Deserialization is reading tree back from the array. Now your task is to 
complete the function serialize which stores the tree into an array A[ ] and 
deSerialize which deserializes the array to tree and returns it.
Note: The structure of tree must be maintained.

*/

void serialize(Node *root,vector<int> &A)
{ 
    if(root==NULL)
    {
        A.push_back(-1);
        return;
    }
    else
    {
        A.push_back(root->data);
        serialize(root->left,A);
        serialize(root->right,A);
    }
    
}

Node* buildTree(vector<int> &A,int* index)
{
    if((*index)==A.size() || A[*index]==-1)
    {
        *index = *index+1;
        return NULL;
    }
    else
    {
        Node* newNode = new Node(A[*index]);
        *index = *index + 1;
        newNode->left = buildTree(A,index);
        newNode->right = buildTree(A,index);
        return newNode;
    }
}

Node * deSerialize(vector<int> &A)
{
   int index = 0;
   return buildTree(A,&index);
}
