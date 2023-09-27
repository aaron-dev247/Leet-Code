
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
    ListNode *reverseList(ListNode *head)
    {
        if (head == nullptr)
            return nullptr;

        ListNode *temp = head;
        ListNode *newHead = new ListNode(head->val);

        while (temp->next != nullptr)
        {
            ListNode *node = new ListNode(temp->next->val, newHead);
            newHead = node;
            temp = temp->next;
        }

        return newHead;
    }
};