#include <vector>
#include <queue>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct CompareListNode
{
    bool operator()(ListNode *l1, ListNode *l2)
        const
    {
        return l1->val > l2->val;
    }
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

        // node with smallest value node will be at the top
        priority_queue<ListNode *, vector<ListNode *>, CompareListNode> pq;
        for (int i = 0; i < n; i++)
        {
            if (lists[i])
                pq.push(lists[i]);
        }

        ListNode *head = nullptr, *tail = nullptr;

        while (pq.size() > 0)
        {
            ListNode *top = pq.top();
            pq.pop(); // pop the smallest value node
            if (top->next != nullptr)
                pq.push(top->next);
            if (head == nullptr)
            {
                head = top;
                tail = top;
            }
            else
            {
                tail->next = top;
                tail = tail->next;
            }
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