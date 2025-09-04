#include <iostream>
using namespace std;

#define OPEN_GREEN "\033[1;32m"
#define OPEN_RED "\033[1;31m"
#define CLOSE_COLOR "\033[0m"

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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *dummy = new ListNode(0);
        ListNode *current = dummy;
        int carry = 0;

        while (l1 != nullptr || l2 != nullptr || carry != 0)
        {
            int sum = carry;
            if (l1 != nullptr)
            {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr)
            {
                sum += l2->val;
                l2 = l2->next;
            }
            carry = sum / 10;
            current->next = new ListNode(sum % 10);
            current = current->next;
        }

        return dummy->next;
    }
};

int main()
{
    Solution solution;
    ListNode *test_case_l1 = new ListNode(2, new ListNode(4, new ListNode(9)));
    ListNode *test_case_l2 = new ListNode(5, new ListNode(6, new ListNode(4, new ListNode(9))));
    ListNode *expected_result = new ListNode(7, new ListNode(0, new ListNode(4, new ListNode(0, new ListNode(1)))));
    ListNode *result = solution.addTwoNumbers(test_case_l1, test_case_l2);

    // Function to print a linked list
    auto printList = [](ListNode *head)
    {
        cout << "[";
        while (head != nullptr)
        {
            cout << head->val;
            if (head->next != nullptr)
            {
                cout << ",";
            }
            head = head->next;
        }
        cout << "]";
    };

    // Function to check if two linked lists are equal
    auto areListsEqual = [](ListNode *l1, ListNode *l2) -> bool
    {
        while (l1 != nullptr && l2 != nullptr)
        {
            if (l1->val != l2->val)
            {
                return false;
            }
            l1 = l1->next;
            l2 = l2->next;
        }
        // If one list is longer than the other
        return (l1 == nullptr && l2 == nullptr);
    };

    // Compare and print result
    bool isCorrect = areListsEqual(result, expected_result);
    if (isCorrect)
    {
        cout << OPEN_GREEN << "CORRECT: ";
        printList(result);
        cout << CLOSE_COLOR << endl;
    }
    else
    {
        cout << OPEN_RED << "WRONG: ";
        cout << "Got: ";
        printList(result);
        cout << ", Expected: ";
        printList(expected_result);
        cout << CLOSE_COLOR << endl;
    }

    return 0;
}