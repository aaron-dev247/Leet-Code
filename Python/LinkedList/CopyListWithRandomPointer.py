
from typing import Optional


class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random


class Solution:
    def copyRandomList(self, head: 'Optional[Node]') -> 'Optional[Node]':

        oldToCopy = {None: None}

        # create nodes without link
        cur = head
        while cur:
            oldToCopy[cur] = Node(cur.val)
            cur = cur.next

        # link nodes
        cur = head
        while cur:
            oldToCopy[cur].next = oldToCopy[cur.next]
            oldToCopy[cur].random = oldToCopy[cur.random]
            cur = cur.next

        return oldToCopy[head]


s = Solution()
s.copyRandomList(Node(1, Node(1)))
