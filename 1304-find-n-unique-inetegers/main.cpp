#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> sumZero(int n)
    {
        vector<int> result;

        if (n % 2 == 0)
        {
            for (int i = 0; i < n; i = i + 2)
            {
                result.push_back(i + 1);
                result.push_back((i + 1) * -1);
            }
        }
        else
        {
            for (int i = 0; i < n - 1; i = i + 2)
            {
                result.push_back(i + 1);
                result.push_back((i + 1) * -1);
            }

            result.push_back(0);
        }

        return result;
    }
};
