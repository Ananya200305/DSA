# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        size = 0
        temp = head 

        while temp : 
            size += 1
            temp = temp.next
        
        if size == 1 and n > size:
            return NULL
        
        n = size - n
        temp = head

        if n == 0:
            head = head.next
            return head
        
        for i in range(1,n):
            temp = temp.next
        
        temp.next = temp.next.next
        return head