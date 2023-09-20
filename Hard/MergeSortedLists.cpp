#include <vector>

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
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        if (lists.size() == 0)
            return {};
        ListNode *head = {};
        ListNode *temp;

        int i = 0;
        while (i < lists.size())
        {
            if (lists[i] != nullptr)
            {
                head = lists[i];
                temp = head;
                i++;
                break;
            }
            i++;
        }

        while (i < lists.size())
        {
            if (lists[i] == nullptr)
            {
                i++;
                continue;
            }

            temp = head;
            ListNode *tempHead = lists[i];
            ListNode *tempNode = tempHead;
            ListNode *tempPrev = nullptr;

            while (tempNode != nullptr && head->val > tempNode->val) // filter out all val less than head(val)
            {
                tempPrev = tempNode;
                tempNode = tempNode->next;
            }

            if (tempPrev != nullptr) // link all lesser value nodes
            {
                tempPrev->next = temp;
                head = tempHead;
            }

            while (tempNode != nullptr && temp != nullptr) // link all middle value nodes
            {
                tempPrev = tempNode;

                if (temp->val == tempNode->val)
                {
                    ListNode *newNode = new ListNode(tempNode->val, temp->next);
                    temp->next = newNode;
                    temp = newNode;
                }
                else if (temp->val < tempNode->val && temp->next != nullptr && temp->next->val >= tempNode->val)
                {
                    ListNode *newNode = new ListNode(tempNode->val, temp->next);
                    temp->next = newNode;
                    temp = temp->next;
                }
                else
                {
                    if (temp->next == nullptr)
                        break;
                    temp = temp->next;
                    continue;
                }

                tempNode = tempNode->next;
            }

            if (tempPrev != nullptr && tempPrev == tempNode)
            {
                temp->next = tempPrev;
            }
            i++;
        }

        return head;
    }
};

int main()
{
    Solution *s = new Solution();
    ListNode *list1 = new ListNode(7);
    list1->next = new ListNode(8);
    list1->next->next = new ListNode(9);

    ListNode *list2 = new ListNode(1);
    list2->next = new ListNode(2);
    list2->next->next = new ListNode(11);
    list2->next->next->next = new ListNode(12);
    vector<ListNode *> lists = {{}};
    s->mergeKLists(lists);
    return 0;
}