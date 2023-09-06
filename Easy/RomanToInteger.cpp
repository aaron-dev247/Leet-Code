#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int romanToInt(string s)
    {
        unordered_map<char, int> umap = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}};

        int num = 0, n = s.length();
        for (int i = 0; i < n; i++)
        {
            if (i + 1 < n && umap[s[i + 1]] > umap[s[i]])
            {
                // subtract the Roman number if the next one is grater
                num -= umap[s[i]];
                continue;
            }
            num += umap[s[i]];
        }
        return num;
    }
};

int main()
{
    Solution *s = new Solution();
    cout << s->romanToInt("MCMXCIV");
    return 0;
}