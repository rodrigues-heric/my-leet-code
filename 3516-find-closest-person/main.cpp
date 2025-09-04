#include <vector>
#include <iostream>
using namespace std;

#define OPEN_GREEN "\033[32m"
#define OPEN_RED "\033[31m"
#define CLOSE_COLOR "\033[0m"

// Given by LeetCode
class Solution
{
public:
    int findClosest(int x, int y, int z)
    {
        int dist_x = abs(x - z);
        int dist_y = abs(y - z);

        if (dist_x == dist_y)
            return 0;
        else if (dist_x < dist_y)
            return 1;
        else
            return 2;
    }
};

// Added for test cases
int main()
{
    Solution solution;
    vector<vector<int>> test_cases = {
        {2, 7, 4},
        {2, 5, 6},
        {1, 5, 3},
    };
    vector<int> expected_results = {1, 2, 0};

    for (size_t i = 0; i < test_cases.size(); ++i)
    {
        int x = test_cases[i][0];
        int y = test_cases[i][1];
        int z = test_cases[i][2];
        int expected = expected_results[i];
        int result = solution.findClosest(x, y, z);
        if (result == expected)
        {
            cout << OPEN_GREEN << "Test case " << i + 1 << " passed." << CLOSE_COLOR << endl;
        }
        else
        {
            cout << OPEN_RED << "Test case " << i + 1 << " failed. Expected " << expected << " but got " << result << "." << CLOSE_COLOR << endl;
        }
    }
}