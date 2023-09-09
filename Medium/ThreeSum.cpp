#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> triplets;
        // have three pointers start at [0] [1] [2]
        int i = 0, j = 1, k = 2, n = nums.size();
        do
        {
            // find all three combinations and add to vector if sum == 0
            if (nums[i] + nums[j] + nums[k] == 0)
            {
                // sort the numbers
                int smallest = min(nums[i], min(nums[j], nums[k]));
                int largest = max(nums[i], max(nums[j], nums[k]));
                int middle = 0 - smallest - largest; // nums[i] + nums[j] + nums[k] - smallest - largest

                bool isExist = false;
                for (int x = 0; x < triplets.size(); x++)
                {
                    if (smallest == triplets[x][0] && middle == triplets[x][1] && largest == triplets[x][2])
                    {
                        // numbers already exist
                        isExist = true;
                        break;
                    }
                }
                if (!isExist)
                {
                    triplets.push_back({smallest, middle, largest});
                }
            }

            if (k < n - 1)
            {
                k++;
                continue;
            }

            if (j < k - 1)
            {
                j++;
                k = j + 1;
                continue;
            }

            if (i < j - 1)
            {
                i++;
                j = i + 1;
                k = j + 1;
                continue;
            }
        } while (i != n - 3);

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