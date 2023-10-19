#include <vector>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> triplets;

        sort(nums.begin(), nums.end());
        int n = nums.size();

        for (int i = 0; i < n - 2; i++)
        {
            // nums[left] + nums[right] can never add up to 0
            if (nums[i] > 0)
                break;

            // skip repeating numbers
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            int left = i + 1, right = n - 1;
            while (left < right)
            {
                int sum = nums[i] + nums[left] + nums[right];
                // need greater sum
                if (sum < 0)
                    left++;
                
                // need lesser sum
                else if (sum > 0)
                    right--;

                // triplet found
                else
                {
                    vector<int> temp = {nums[i], nums[left], nums[right]};
                    triplets.push_back(temp);

                    // skip repeating numbers
                    while (left < right && nums[left] == temp[1])
                        left++;

                    while (left < right && nums[right] == temp[2])
                        right--;
                }
            }
        }

        return triplets;
    }
};

int main()
{
    Solution *s = new Solution();
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    s->threeSum(nums);
    return 0;
}