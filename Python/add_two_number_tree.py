# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        # Initial ListNode value
        initial = ListNode(0)

        # Keep initial value
        tmp = initial

        # Carry is the number that keep when addition gte 10, 1 is carry
        carry = 0

        # Loop until l1 and l2 and carry is NoneType or 0 Value
        # or operator is elvis operator
        while l1 or l2 or carry:
            # Convert value if NoneType to 0
            v1 = l1.val if l1 else 0
            v2 = l2.val if l2 else 0

            # Keep addition value into variable
            v3 = v1 + v2 + carry

            # Get carry value by divide v3 value // 10
            carry = v3 // 10

            # Get exact value behind carry
            v3 = v3 % 10

            # applied v3 values as new node
            tmp.next = ListNode(v3)

            # update tmp value into next value
            tmp = tmp.next

            # Move into l1 and l2 next value
            l1 = l1.next if l1 else None
            l2 = l2.next if l2 else None

        # Returning final value
        return initial.next

if __name__ == "__main__":
    result = Solution().addTwoNumbers(l1=ListNode(3, ListNode(5, ListNode(4))), l2=ListNode(6, ListNode(7, ListNode(3))))
    while result:
        print(result.val)
        result = result.next
