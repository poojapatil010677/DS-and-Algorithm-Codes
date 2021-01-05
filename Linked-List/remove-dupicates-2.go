/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func deleteDuplicates(head *ListNode) *ListNode {
    dummy := &ListNode{Next:head}
    prev := dummy
    temp := dummy.Next
    
    for temp!= nil && temp.Next != nil {
            if temp.Val != temp.Next.Val {
                prev = temp
                temp = temp.Next
            } else {
                for temp.Next!=nil && temp.Val == temp.Next.Val {
                    temp.Next = temp.Next.Next
                }
                prev.Next = temp.Next
                temp = temp.Next
            }
    }
    return dummy.Next
}
