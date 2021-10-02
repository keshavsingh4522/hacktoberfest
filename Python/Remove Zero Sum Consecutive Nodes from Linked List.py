class Solution:
    def removeZeroSumSublists(self, head: ListNode) -> ListNode:
        
        dummy = ListNode(0)
        dummy.next = head
        curr = head
        head = dummy
        while head:
            curr_summ = 0
            while curr:
                curr_summ += curr.val
                if curr_summ == 0:
                    head.next = curr.next
                curr = curr.next
            head = head.next
            if head:
                curr = head.next
        
        return dummy.next 
