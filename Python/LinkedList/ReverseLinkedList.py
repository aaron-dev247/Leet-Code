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
        if not head:
            return None
        
        newHead = head

        if head.next:
            newHead = self.reverseList(head.next)
            head.next.next = head
        head.next = None
        
        return newHead

    

s = Solution()
head = ListNode(1)
head.next = ListNode(2)
head.next.next = ListNode(3)
s.reverseList(head)