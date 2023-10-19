#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        string prefix = "";
        int index = 0;
        bool flag = false;
        while (index < strs[0].length())
        {
            // store first string's index char for comparison
            char temp = strs[0][index];
            for (int i = 1; i < strs.size(); i++)
            {
                if (index == strs[i].length() || strs[i][index] != temp)
                {
                    // break loop if index out of bound or prefix not match
                    flag = true;
                }
            }
            if (flag)
            {
                break;
            }
            prefix += temp;
            index++;
        }

        return prefix;
    }
};

int main()
{
    Solution *s = new Solution();
    vector<string> strs = {"dog", "racecar", "car"};
    cout << s->longestCommonPrefix(strs);
    return 0;
}