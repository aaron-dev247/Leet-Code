#include <vector>
#include <unordered_map>

using namespace std;

/**
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */
class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> umap;
        int n = nums.size();
        // Populate map with the count of each number
        for (int i = 0; i < n; i++)
            umap[nums[i]]++;

        vector<vector<int>> freq(n);

        for (auto item : umap)
            // -1 because index starts at 0
            freq[item.second - 1].push_back(item.first);

        vector<int> ans;

        for (int i = n - 1; i >= 0; i--)
        {
            if (!freq[i].empty())
            {
                if (k >= freq[i].size())
                {
                    ans.insert(ans.end(), freq[i].begin(), freq[i].end());
                    k -= freq[i].size();
                    if (k == 0)
                        break;
                }
                else
                {
                    // Insert first k elements of freq[i] into ans
                    ans.insert(ans.end(), freq[i].begin(), freq[i].begin() + k);
                    break;
                }
            }
        }
        return ans;
    }
};

int main()
{
    vector<int> nums = {1, 1, 2, 2, 3, 3};
    Solution *s = new Solution();
    s->topKFrequent(nums, 1);
    return 0;
}