from typing import Optional


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        top, bot = l1, l2

        newHead = ListNode()
        tmp = newHead

        carry = 0
        while top or bot or carry:
            v1 = top.val if top else 0
            v2 = bot.val if bot else 0
            sum = v1 + v2 + carry
            carry = sum // 10
            sum %= 10
            tmp.next = ListNode(sum)
            tmp = tmp.next
            top = top.next if top else None
            bot = bot.next if bot else None

        return newHead.next


s = Solution()
s.addTwoNumbers(ListNode(2, ListNode(4, ListNode(3))),
                ListNode(5, ListNode(6, ListNode(4))))
