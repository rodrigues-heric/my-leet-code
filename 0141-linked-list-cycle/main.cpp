#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        if (!head)
            return false;
        if (!head->next)
            return false;
        if (!head->next->next)
            return false;

        ListNode *slow = head;
        ListNode *fast = head->next->next;

        while (slow && fast)
        {
            if (slow == fast)
                return true;

            if (slow->next && fast->next && fast->next->next)
            {
                slow = slow->next;
                fast = fast->next->next;
            }
            else
            {
                return false;
            }
        }

        return false;
    }
};