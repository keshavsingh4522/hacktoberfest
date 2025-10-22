# Definition for singly-linked list.
# class ListNode
#     attr_accessor :val, :next
#     def initialize(val = 0, _next = nil)
#         @val = val
#         @next = _next
#     end
# end

def reverse_k_group(head, k)
  return head if head.nil? || k == 1

  dummy = ListNode.new(0)
  dummy.next = head
  prev_group = dummy

  while true
    kth = prev_group
    k.times do
      kth = kth.next
      return dummy.next if kth.nil?
    end

    group_next = kth.next
    prev, curr = group_next, prev_group.next

    while curr != group_next
      temp = curr.next
      curr.next = prev
      prev = curr
      curr = temp
    end

    temp = prev_group.next
    prev_group.next = kth
    prev_group = temp
  end
end
