class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution(object):
    def reverseList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        prev, cur = None, head

        while cur is not None:
            temp = cur.next
            cur.next = prev
            prev = cur
            cur = temp
            
        return prev