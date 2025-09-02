// https://leetcode.com/problems/roman-to-integer/

#include <string>
#include <unordered_map>
#include <vector>
#include <iostream>

using namespace std;

#define OPEN_GREEN "\e[32m"
#define OPEN_RED "\e[31m"
#define CLOSE "\e[0m"

unordered_map<char, int> map_roman = {
    {'I', 1},
    {'V', 5},
    {'X', 10},
    {'L', 50},
    {'C', 100},
    {'D', 500},
    {'M', 1000},
};

class Solution
{
public:
    int romanToInt(string s)
    {
        int result = 0;
        int n = s.length();

        for (int i = 0; i < n; i++)
        {
            if (i + 1 < n && map_roman[s[i]] < map_roman[s[i + 1]])
            {
                result -= map_roman[s[i]];
            }
            else
            {
                result += map_roman[s[i]];
            }
        }

        return result;
    }
};

int main()
{
    Solution solution;
    vector<string> test_cases = {"III", "IV", "IX", "LVIII", "MCMXCIV", "MDCCCLXXXIV"};
    vector<int> results = {3, 4, 9, 58, 1994, 1884};

    for (size_t i = 0; i < test_cases.size(); ++i)
    {
        int integer = solution.romanToInt(test_cases[i]);

        if (integer == results[i])
        {
            cout << OPEN_GREEN << "Test case " << i + 1 << " passed. Expected: " << results[i] << ", Got: " << integer << CLOSE << endl;
        }
        else
        {
            cout << OPEN_RED << "Test case " << i + 1 << " failed. Expected: " << results[i] << ", Got: " << integer << CLOSE << endl;
        }
    }

    return 0;
}
