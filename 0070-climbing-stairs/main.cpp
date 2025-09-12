#include <cmath>

#include <iostream>
using namespace std;

class Solution
{
public:
    int climbStairs(int n)
    {
        return (
            (pow((1 + sqrt(5)) / 2, n + 1) - pow((1 - sqrt(5)) / 2, n + 1)) / sqrt(5));
    }
};

int main()
{
    Solution solution;
    int n = 5;
    int result = solution.climbStairs(n);
    cout << result << endl;
    return 0;
}