#include <vector>
#include <algorithm>

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
        int n = lists.size();
        if (n == 0)
            return nullptr;
        if (n == 1)
            return lists[0];

        ListNode *head, *tempNode;

        vector<int> tempVec;
        int i = 0;
        while (i < n)
        {
            if (lists[i] == nullptr) // skip empty list node
            {
                i++;
                continue;
            }

            head = lists[i];
            tempNode = head;
            while (tempNode->next != nullptr)
            {
                tempVec.push_back(tempNode->val);
                tempNode = tempNode->next;
            }
            tempVec.push_back(tempNode->val);
            i++;
            break;
        }

        while (i < n)
        {
            if (lists[i] == nullptr) // skip empty list node
            {
                i++;
                continue;
            }
            ListNode *temp = lists[i];
            tempNode->next = temp;
            while (temp->next != nullptr)
            {
                tempVec.push_back(temp->val);
                temp = temp->next;
            }
            tempVec.push_back(temp->val);
            tempNode = temp;
            i++;
        }

        if (tempVec.size() == 0)
            return nullptr;
        sort(tempVec.begin(), tempVec.end());

        tempNode = head;
        for (int num : tempVec)
        {
            tempNode->val = num;
            tempNode = tempNode->next;
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
    vector<ListNode *> lists = {list1, list2};
    s->mergeKLists(lists);
    return 0;
}