package Binary-Trees;

import java.util.ArrayList;

public class PreorderTraversal {
    static void helper(ArrayList<Integer> pre,Node root)
    {
        if(root==null)
            return;
        else
        {
            pre.add(root.data);
            helper(pre,root.left);
            helper(pre,root.right);
        }
    }
    /* Computes the number of nodes in a tree. */
    static ArrayList<Integer> preorder(Node root)
    {
        ArrayList<Integer> pre = new ArrayList<Integer>();
        helper(pre,root);
        return pre;
    }

}
