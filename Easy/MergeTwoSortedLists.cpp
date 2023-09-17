
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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode *mergeList = new ListNode();
        ListNode *temp = mergeList;
        ListNode *temp1 = list1, *temp2 = list2;

        while (temp1 != nullptr && temp2 != nullptr)
        {
            if (temp1->val < temp2->val)
            {
                temp->next = new ListNode(temp1->val);
                temp = temp->next;
                temp1 = temp1->next;
            }
            else
            {
                temp->next = new ListNode(temp2->val);
                temp = temp->next;
                temp2 = temp2->next;
            }
        }

        // adding the remaining nodes
        while (temp1 != nullptr)
        {
            temp->next = new ListNode(temp1->val);
            temp = temp->next;
            temp1 = temp1->next;
        }

        while (temp2 != nullptr)
        {
            temp->next = new ListNode(temp2->val);
            temp = temp->next;
            temp2 = temp2->next;
        }

        return mergeList->next;
    }
};

int main()
{
    Solution *s = new Solution();
    ListNode *list1 = new ListNode(1);
    list1->next = new ListNode(2);
    list1->next->next = new ListNode(4);

    ListNode *list2 = new ListNode(1);
    list2->next = new ListNode(3);
    list2->next->next = new ListNode(4);

    s->mergeTwoLists(list1, list2);
    return 0;
}