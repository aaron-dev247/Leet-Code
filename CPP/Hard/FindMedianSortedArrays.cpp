#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        // get the total size of the two vectors
        int totalSize = nums1.size() + nums2.size();
        // caulculate the median index
        int medianIndex = totalSize / 2;

        vector<int> temp;
        int index1 = 0, index2 = 0;
        // combind two vectors until median index
        while (temp.size() < medianIndex + 1)
        {
            int num1 = INT_MAX, num2 = INT_MAX;
            if (index1 < nums1.size())
            {
                num1 = nums1.at(index1);
            }
            if (index2 < nums2.size())
            {
                num2 = nums2.at(index2);
            }
            // push the smallest number to temp
            if (num1 > num2)
            {
                temp.push_back(num2);
                index2++;
            }
            else
            {
                temp.push_back(num1);
                index1++;
            }
        }
        if (totalSize % 2 == 0)
        {
            return (temp[medianIndex] + temp[medianIndex - 1]) / 2.0;
        }
        return temp[medianIndex];
    }
};

int main()
{
    vector<int> nums1 = {1, 2};
    vector<int> nums2 = {3, 4};
    Solution *s = new Solution();
    cout << s->findMedianSortedArrays(nums1, nums2);
    return 0;
}