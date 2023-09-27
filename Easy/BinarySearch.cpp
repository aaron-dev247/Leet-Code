#include <vector>

using namespace std;

/**
 * Time Complexity: O(log n)
 * Space Complexity: O(1)
 */
class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int left = 0, right = nums.size() - 1;

        while (left <= right)
        {
            int mid = left + ((right - left) / 2);

            // eliminate all numbers to the right
            if (nums[mid] > target)
                right = mid - 1;
            // eliminate all numbers to the left
            else if (nums[mid] < target)
                left = mid + 1;
            else
                return mid;
        }
        return -1;
    }
};