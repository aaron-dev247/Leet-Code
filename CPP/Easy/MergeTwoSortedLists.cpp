
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/**
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode *mergeList = new ListNode();
        ListNode *temp = mergeList;

        while (list1 && list2)
        {
            if (list1->val < list2->val)
            {
                temp->next = list1;
                list1 = list1->next;
            }
            else
            {
                temp->next = list2;
                list2 = list2->next;
            }
            temp = temp->next;
        }

        // adding the remaining nodes
        if (list1)
            temp->next = list1;
        else
            temp->next = list2;

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