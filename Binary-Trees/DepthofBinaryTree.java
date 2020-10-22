package Binary-Trees;

/*
public class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode() {}
    TreeNode(int val) { this.val = val; }
    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
     }
}
*/
public class DepthofBinaryTree {   
    int helper(TreeNode root)
    {
        if(root.left==null && root.right==null)
            return 1;
        else  if(root.left==null)
            return 1+helper(root.right);
        else if(root.right==null)
            return 1+helper(root.left);
        else
        {
            return 1 + Math.min(helper(root.left),helper(root.right));
        }
    }
    
    public int minDepth(TreeNode root) {
        if(root==null)
            return 0;
        int res = helper(root);
        return res;
    }

}
