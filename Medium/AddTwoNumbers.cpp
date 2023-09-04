/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#include <iostream>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *head = new ListNode();
        ListNode *temp = head;
        int carry = 0;
        while (l1 || l2 || carry)
        {
            int sum = 0;

            if (l1) // if l1 is not null
            {
                sum += l1->val;
                l1 = l1->next;
            }

            if (l2) // if l2 is not null
            {
                sum += l2->val;
                l2 = l2->next;
            }
            sum += carry;
            carry = sum / 10;
            temp->next = new ListNode(sum % 10);
            temp = temp->next;
        }
        return head->next;
    }
};

int main(int argc, char const *argv[])
{
    Solution *s = new Solution();
    ListNode *l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);

    ListNode *l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);
    ListNode *node = s->addTwoNumbers(l1, l2);
    // ListNode *node = s->addTwoNumbers(new ListNode(9), new ListNode(9));
    while (node)
    {
        std::cout << node->val;
        node = node->next;
    }
    return 0;
}
