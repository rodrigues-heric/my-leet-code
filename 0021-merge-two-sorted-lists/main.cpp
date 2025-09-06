#include <iostream>
#include <vector>
using namespace std;

#define OPEN_GREEN "\033[32m"
#define OPEN_RED "\033[31m"s
#define CLOSE_COLOR "\033[0m"

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

vector<int> listToVector(ListNode *head)
{
    vector<int> result;
    while (head)
    {
        result.push_back(head->val);
        head = head->next;
    }
    return result;
}

void printList(ListNode *head)
{
    vector<int> values = listToVector(head);
    cout << "[";
    for (size_t i = 0; i < values.size(); i++)
    {
        cout << values[i];
        if (i < values.size() - 1)
        {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}

bool testListsEqual(ListNode *list1, ListNode *list2)
{
    while (list1 && list2)
    {
        if (list1->val != list2->val)
        {
            return false;
        }
        list1 = list1->next;
        list2 = list2->next;
    }

    if (list1 || list2)
    {
        return false;
    }

    return true;
}

class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode dummy(0);
        ListNode *tail = &dummy;

        while (list1 && list2)
        {
            if (list1->val <= list2->val)
            {
                tail->next = list1;
                list1 = list1->next;
            }
            else
            {
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;
        }

        tail->next = list1 ? list1 : list2;

        return dummy.next;
    }
};

int main()
{
    Solution solution;
    ListNode *list1 = new ListNode(1, new ListNode(2, new ListNode(4)));
    ListNode *list2 = new ListNode(1, new ListNode(3, new ListNode(4)));
    ListNode *mergedList = solution.mergeTwoLists(list1, list2);
    ListNode *expectedList = new ListNode(1, new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(4))))));

    if (testListsEqual(mergedList, expectedList))
    {
        cout << OPEN_GREEN << "PASSED" << CLOSE_COLOR << endl;
    }
    else
    {
        cout << OPEN_RED << "FAILED" << endl;
        cout << "Expected: ";
        printList(expectedList);
        cout << "Got: ";
        printList(mergedList);
        cout << CLOSE_COLOR;
    }

    return 0;
}