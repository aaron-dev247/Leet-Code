#include <vector>
#include <unordered_set>

using namespace std;

/**
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */
class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        unordered_set<int> uset;
        for (int i = 0; i < nums.size(); i++)
        {
            if (uset.find(nums[i]) != uset.end())
                return true;

            uset.insert(nums[i]);
        }
        return false;
    }
};
