#include <string>
#include <iostream>

using namespace std;

class Solution
{
public:
    bool isPalindrome(int x)
    {
        string number = to_string(x);
        int j = number.length() - 1;
        int i = 0;

        bool is_palindrome = true;
        while (i <= j)
        {
            if (number[i] != number[j])
            {
                is_palindrome = false;
                i = j + 1;
            }

            i++;
            j--;
        }

        return is_palindrome;
    }
};

int main()
{
    Solution solution;

    int test_cases[] = {121, -121, 10, 12321};

    for (int num : test_cases)
    {
        bool result = solution.isPalindrome(num);
        cout << num << " is " << (result ? "a palindrome" : "not a palindrome") << endl;
    }

    return 0;
}