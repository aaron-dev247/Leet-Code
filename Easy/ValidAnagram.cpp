#include <string>
#include <unordered_map>

using namespace std;

/**
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */
class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        int n = s.length(), m = t.length();
        if (n != m)
            return false;
        unordered_map<char, int> umap;

        for (int i = 0; i < n; i++)
        {
            umap[s[i]]++;
            umap[t[i]]--;
        }
        for (auto &item : umap)
        {
            if (item.second != 0)
                return false;
        }

        return true;
    }
};
