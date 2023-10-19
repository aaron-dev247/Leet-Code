#include <string>
#include <iostream>
#include <vector>

using namespace ::std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        vector<int> asciiList(256, -1); // there are 256 ascii codes
        int maxLen = 0, start = -1;
        for (int i = 0; i < s.length(); i++)
        {
            if (asciiList[s[i]] > start)
            {
                // the char s[i] repeating
                start = asciiList[s[i]];
            }
            asciiList[s[i]] = i;
            // continue + 1 to maxLen if no char repeating
            maxLen = max(maxLen, i - start);
        }
        return maxLen;
    }
};

int main(int argc, char const *argv[])
{
    Solution *s = new Solution();
    cout << s->lengthOfLongestSubstring("abcabcbb");
    return 0;
}
