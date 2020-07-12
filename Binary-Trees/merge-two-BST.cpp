/*

Merge Two BSTs

Given two BST, Return elements of both BSTs in sorted form.

Example:
Input:
2
5 3 6 2 4
2 1 3 N N N 7 6
12 9 N 6 11
8 5 10 2

Output:
1 2 2 3 3 4 5 6 6 7
2 5 6 8 9 10 11 12

Expected Time Complexity: O(M+N) where M and N are the sizes if the two BSTs.
Expected Auxiliary Space: O(Height of BST1 + Height of BST2).

*/

vector<int> merge(Node *root1, Node *root2)
{
   vector<int> res;
   stack<Node*> s1;
   stack<Node*> s2;
   Node* node1 = root1;
   Node* node2 = root2;
   
   while(true)
   {
       if(node1)
       {
           while(node1)
           {
               s1.push(node1);
               node1 = node1->left;
           }
       }
       
       if(node2)
       {
           while(node2)
           {
               s2.push(node2);
               node2 = node2->left;
           }
       }
 
       
       if(!s1.empty() && !s2.empty())
       {
           if(s1.top()->data <= s2.top()->data)
           {
               res.push_back(s1.top()->data);
               node1 = s1.top()->right;
               s1.pop();
           }
           else
           {
            res.push_back(s2.top()->data);
            node2 = s2.top()->right;
            s2.pop();  
           }
       }
       
       else if(!s1.empty())
       {
           res.push_back(s1.top()->data);
           node1 = s1.top()->right;
           s1.pop();           
       }
       else if(!s2.empty())
       {
           res.push_back(s2.top()->data);
           node2 = s2.top()->right;
           s2.pop();           
       }
       
       else if(s1.empty() && s2.empty()) break;
   }
   return res;
}
