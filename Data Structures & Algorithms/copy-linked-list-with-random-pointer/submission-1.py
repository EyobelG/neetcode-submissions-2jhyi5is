"""
# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random
"""

# Each node: [val, random_index] (index 0 = val, index 1 = rand_Idx)
from collections import defaultdict
class Solution:
    def copyRandomList(self, head: 'Optional[Node]') -> 'Optional[Node]':
        if not head:
            return None
        node_map = {None : None}

        current = head
        while current:
            node_map[current] = Node(current.val)
            current = current.next
        current = head
        while current:
            copy = node_map[current]
            copy.next = node_map[current.next]

            copy.random = node_map[current.random]

            current = current.next
        return node_map[head]
        
            





"""
class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        dummy = ListNode(0, head)
        first = dummy
        second = dummy

        for _ in range(n + 1):
            first = first.next
        
        while first:
            first = first.next
            second = second.next

        second.next = second.next.next

        return dummy.next
"""