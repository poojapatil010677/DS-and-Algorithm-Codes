/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func inorder(root *TreeNode, vals []int) []int {
    if root == nil {
        return vals
    }
     
    vals = inorder(root.Left,vals)
    vals = append(vals,root.Val)
    vals = inorder(root.Right,vals)
    
    return vals
}

func increasingBST(root *TreeNode) *TreeNode {
    
    if root==nil {
        return nil
    }
    
    vals := inorder(root,[]int{})
    hdnode := &TreeNode{Val:vals[0]}
    slnode := hdnode
    for _,val := range vals[1:] {
        newNode := &TreeNode{Val:val}
        slnode.Right = newNode
        slnode = slnode.Right
    }
    
    return hdnode
}
