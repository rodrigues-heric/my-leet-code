#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;

        while (i >= 0 && j >= 0)
        {
            if (nums1[i] > nums2[j])
            {
                nums1[k--] = nums1[i--];
            }
            else
            {
                nums1[k--] = nums2[j--];
            }
        }

        while (j >= 0)
        {
            nums1[k--] = nums2[j--];
        }
    }
};

int main()
{
    Solution sol;
    vector<int> nums1 = {2, 0};
    vector<int> nums2 = {1};
    sol.merge(nums1, 1, nums2, 1);

    for (int num : nums1)
    {
        cout << num << " ";
    }

    return 0;
}