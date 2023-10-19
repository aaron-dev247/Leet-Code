#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

/**
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */
class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        int n = strs.size();
        if (n == 1)
            return {{strs[0]}};

        unordered_map<string, vector<string>> umap;

        for (int i = 0; i < n; i++)
        {
            string key = strs[i];
            sort(key.begin(), key.end());
            umap[key].push_back(strs[i]);
        }

        vector<vector<string>> ans;

        for (auto &item : umap)
        {
            ans.push_back(item.second);
        }

        return ans;
    }
};

int main()
{
    Solution *s = new Solution();
    vector<string> vec = {
        "cia",
        "bbc"};
    s->groupAnagrams(vec);
    return 0;
}