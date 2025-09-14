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
    ListNode *deleteDuplicates(ListNode *head)
    {
        ListNode *setList = head;
        ListNode *dummy = setList;

        while (setList && setList->next)
        {
            if (setList->next->val == setList->val)
            {
                setList->next = setList->next->next;
                continue;
            }
            setList = setList->next;
        }

        return dummy;
    }
};