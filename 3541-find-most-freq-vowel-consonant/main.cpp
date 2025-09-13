#include <string>
#include <unordered_map>
#include <iostream>
using namespace std;

class Solution
{
public:
    int maxFreqSum(string s)
    {
        unordered_map<char, int> freq;
        int consonant = 0;
        int vowel = 0;

        for (char c : s)
            freq[c]++;

        for (auto &[ch, count] : freq)
        {
            if (string("aeiou").find(ch) != string::npos)
                vowel = max(vowel, count);
            else
                consonant = max(consonant, count);
        }

        return consonant + vowel;
    }
};