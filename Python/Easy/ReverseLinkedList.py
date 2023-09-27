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
        if head is None:
            return None
        
        temp = head

        newHead = ListNode(head.val)

        while temp.next is not None:
            node = ListNode(temp.next.val, newHead)
            newHead = node
            temp = temp.next

        return newHead