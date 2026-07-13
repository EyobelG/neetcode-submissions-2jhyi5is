# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:
        slow = fast = head
        while fast and fast.next:
            slow, fast = slow.next, fast.next.next
        secondHalf = slow.next
        slow.next = None

        prev, curr = None, secondHalf
        while curr:
            nextTemp = curr.next
            curr.next = prev
            prev, curr = curr, nextTemp
        first, second = head, prev

        while second:
            tmp1, tmp2 = first.next, second.next
            first.next, second.next = second, tmp1
            first, second = tmp1, tmp2
        