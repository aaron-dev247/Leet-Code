#include <iostream>

using namespace std;

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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        int length = 1;
        ListNode *temp = head;

        // get node count
        while (temp->next != nullptr)
        {
            length++;
            temp = temp->next;
        }

        temp = head;
        ListNode *newHead = new ListNode();
        ListNode *newTemp = newHead;

        for (int i = length; i > 0; i--)
        {
            if (i == n)
            {
                // skip the "remove" node
                temp = temp->next;
                continue;
            }

            newTemp->next = new ListNode(temp->val);
            newTemp = newTemp->next;

            temp = temp->next;
            if (temp == nullptr)
                break;
        }

        return newHead->next;
    }
};

int main()
{
    Solution *s = new Solution();
    ListNode *head = new ListNode(1);
    ListNode *temp = head;
    temp->next = new ListNode(2);
    temp = temp->next;

    s->removeNthFromEnd(head, 2);
    return 0;
}