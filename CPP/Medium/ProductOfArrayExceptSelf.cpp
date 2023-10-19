#include <vector>

using namespace std;

/**
 * Time Complexity: O(n)
 * Space Complexity: O(1), result vector doesn't count
 */
class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        vector<int> answer;
        int n = nums.size(), prefix = 1, postfix = 1;

        for (int i = 0; i < n; i++)
        {
            answer.push_back(prefix);
            prefix *= nums[i];
        }

        for (int i = n - 1; i >= 0; i--)
        {
            answer[i] *= postfix;
            postfix *= nums[i];
        }

        return answer;
    }
};

int main()
{
    Solution *s = new Solution();
    vector<int> nums = {1, 2, 3, 4};
    s->productExceptSelf(nums);
    return 0;
}