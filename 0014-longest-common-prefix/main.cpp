#include <string>
#include <vector>
#include <iostream>
using namespace std;

#define OPEN_GREEN "\033[32m"
#define OPEN_RED "\033[31m"
#define CLOSE "\033[0m"

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        if (strs.empty())
            return "";

        string prefix = strs[0];
        for (size_t i = 1; i < strs.size(); i++)
        {
            while (strs[i].find(prefix) != 0)
            {
                prefix = prefix.substr(0, prefix.length() - 1);
                if (prefix.empty())
                    return "";
            }
        }

        return prefix;
    }
};

int main()
{
    Solution solution;
    vector<string> test_case_1 = {"flower", "flow", "flight"};
    vector<string> test_case_2 = {"dog", "racecar", "car"};

    string expected_result_1 = "fl";
    string expected_result_2 = "";

    string result_1 = solution.longestCommonPrefix(test_case_1);
    string result_2 = solution.longestCommonPrefix(test_case_2);

    if (result_1 == expected_result_1)
    {
        cout << OPEN_GREEN << "Test case 1 passed!" << CLOSE << endl;
    }
    else
    {
        cout << OPEN_RED << "Test case 1 failed! Expected: " << expected_result_1 << ", Got: " << result_1 << CLOSE << endl;
    }

    if (result_2 == expected_result_2)
    {
        cout << OPEN_GREEN << "Test case 2 passed!" << CLOSE << endl;
    }
    else
    {
        cout << OPEN_RED << "Test case 2 failed! Expected: " << expected_result_2 << ", Got: " << result_2 << CLOSE << endl;
    }

    return 0;
}