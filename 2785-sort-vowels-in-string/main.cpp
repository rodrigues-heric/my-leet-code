#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution
{
public:
    string sortVowels(string s)
    {
        vector<char> vowels = {
            'a',
            'e',
            'i',
            'o',
            'u',
            'A',
            'E',
            'I',
            'O',
            'U',
        };
        vector<int> vowels_indexes;
        vector<char> vowels_present;

        int size = s.size();
        for (int i = 0; i < size; i++)
        {
            auto it = find(vowels.begin(), vowels.end(), s[i]);

            if (it != vowels.end())
            {
                vowels_indexes.push_back(i);
                vowels_present.push_back(s[i]);
            }
        }

        sort(vowels_present.begin(), vowels_present.end());
        int vowels_size = vowels_present.size();

        for (int i = 0; i < vowels_size; i++)
            s[vowels_indexes[i]] = vowels_present[i];

        return s;
    }
};

int main()
{
    string test_case_1 = "lEetcOde";
    string test_case_2 = "lYmpH";
    string expected_1 = "lEOtcede";
    string expected_2 = "lYmpH";

    Solution solution;
    string case_1 = solution.sortVowels(test_case_1);
    string case_2 = solution.sortVowels(test_case_2);

    if (case_1 == expected_1)
        cout << "CASE 1: PASSED!" << endl;
    else
        cout << "CASE 1: FAILED!" << endl;

    if (case_2 == expected_2)
        cout << "CASE 2: PASSED!" << endl;
    else
        cout << "CASE 2: FAILED!" << endl;

    return 0;
}