#include <algorithm>
#include <string>
#include <iostream>
using namespace std;

class Solution
{
public:
    char findTheDifference(string s, string t)
    {
        std::sort(s.begin(), s.end());
        std::sort(t.begin(), t.end());
        char different;

        int word_size = t.size();
        for (int i = 0; i < word_size; i++)
        {
            if (s[i] != t[i])
            {
                different = t[i];
                i = word_size + 1;
            };
        }

        return different;
    }
};