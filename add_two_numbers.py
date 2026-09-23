# Definition for singly-linked list.
class ListNode:
     def __init__(self, val=0, next=None):
         self.val = val
         self.next = next
from typing import Optional


class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        res = ListNode()
        c = 0
        point = res
        while l1 is not None and l2 is not None:
            tmp = l1.val + l2.val + c
            c = tmp // 10
            num = tmp % 10
            new_node = ListNode(num)
            point.next = new_node
            point = point.next

            l1 = l1.next
            l2 = l2.next

        if l1 is not None:
            tmp = l1.val + c
            c = tmp // 10
            num = tmp % 10
            new_node = ListNode(num)
            point.next = new_node
            point = point.next

            l1 = l1.next
        if l2 is not None:
            tmp = l2.val + c  
            c = tmp // 10
            num = tmp % 10
            new_node = ListNode(num)
            point.next = new_node
            point = point.next

            l2 = l2.next
        
        if c != 0:
            new_node = ListNode(c)
            point.next = new_node
            
        return res.next
    
    
def main():
    nums1 = [9,9,9,9,9,9,9]
    l1 = ListNode()
    helper = l1
    for num in nums1:
        tmp  = ListNode(num)
        helper.next = tmp
        helper = helper.next

    nums2 = [9,9,9,9]

    l2 = ListNode()
    helper = l2
    for num in nums2:
        tmp  = ListNode(num)
        helper.next = tmp
        helper = helper.next
        
    sol = Solution()
    print(sol.addTwoNumbers(l1.next, l2.next))

if __name__ == "__main__":
    main()