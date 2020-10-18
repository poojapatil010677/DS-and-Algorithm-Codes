/* 
class Node
{
    int data;
    Node left, right;

    Node(int item)
    {
        data = item;
        left = right = null;
    }
}
 */

class Solution {
    int height(Node node) {
        if(node==null)
            return 0;
        else
        {
            int l = height(node.left);
            int r = height(node.right);
            return 1+Math.max(l,r);
        }
    }
}