#include <stack>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

// By me
#define OPEN_GREEN "\033[32m"
#define OPEN_RED "\033[31m"
#define CLOSE_COLOR "\033[0m"

bool is_open(char c)
{
    return c == '(' || c == '[' || c == '{';
}

bool is_equivalent(char open, char close)
{
    if (open == '(' && close == ')')
        return true;
    if (open == '[' && close == ']')
        return true;
    if (open == '{' && close == '}')
        return true;
    return false;
}

// BY LeetCode
class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> stack_brackets;

        for (auto c : s)
        {
            if (is_open(c))
            {
                stack_brackets.push(c);
            }
            else
            {
                if (stack_brackets.empty())
                    return false;

                auto top = stack_brackets.top();

                if (!is_equivalent(top, c))
                    return false;
                else
                    stack_brackets.pop();
            }
        }

        return stack_brackets.empty() ? true : false;
    }
};

// By me
int main()
{
    Solution solution;
    vector<string> test_cases = {"()", "()[]{}", "(]", "([)]", "{[]}"};
    vector<bool> expected = {true, true, false, false, true};

    for (size_t i = 0; i < test_cases.size(); ++i)
    {
        bool result = solution.isValid(test_cases[i]);
        if (result == expected[i])
        {
            cout << OPEN_GREEN << "Test case " << i << " passed." << CLOSE_COLOR << endl;
        }
        else
        {
            cout << OPEN_RED << "Test case " << i << " failed." << CLOSE_COLOR << endl;
        }
    }

    return 0;
}