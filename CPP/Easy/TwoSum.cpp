#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> uMap;
        for (int i = 0; i < nums.size(); i++)
        {
            int complement = target - nums[i];
            if (uMap.find(complement) != uMap.end())
            {
                // found the number
                return {uMap[complement], i};
            }
            uMap[nums[i]] = i;
        }
        return {}; // numbers not found
    }
};

int main()
{
    vector<int> v = {2, 7, 11, 15};
    Solution *s = new Solution();
    s->twoSum(v, 9);
    return 0;
}