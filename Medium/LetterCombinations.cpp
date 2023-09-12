#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    vector<string> letterCombinations(string digits)
    {
        if (digits.size() == 0)
            return {};

        vector<string> letters;

        unordered_map<char, vector<string>> umap = {
            {'2', {"a", "b", "c"}},
            {'3', {"d", "e", "f"}},
            {'4', {"g", "h", "i"}},
            {'5', {"j", "k", "l"}},
            {'6', {"m", "n", "o"}},
            {'7', {"p", "q", "r", "s"}},
            {'8', {"t", "u", "v"}},
            {'9', {"w", "x", "y", "z"}}};
        int first = 0, second = 0, third = 0, fourth = 0;
        int n = digits.size();

        while (first < umap[digits[0]].size())
        {

            string temp = umap[digits[0]][first];

            if (n > 1)
            {
                temp += umap[digits[1]][second];
            }

            if (n > 2)
            {
                temp += umap[digits[2]][third];
            }

            if (n > 3)
            {
                temp += umap[digits[3]][fourth];
            }

            letters.push_back(temp);

            // increment of first, second, third, fourth pointers
            if (n > 3 && fourth < umap[digits[3]].size() - 1)
            {
                fourth++;
                continue;
            }
            else
            {
                // reset forth pointer
                fourth = 0;
            }

            if (n > 2 && third < umap[digits[2]].size() - 1)
            {
                third++;
                continue;
            }
            else
            {
                // reset third pointer
                third = 0;
            }

            if (n > 1 && second < umap[digits[1]].size() - 1)
            {
                second++;
                continue;
            }
            else
            {
                // reset second pointer
                second = 0;
            }

            first++;
        }
        return letters;
    }
};

int main()
{
    Solution *s = new Solution();
    s->letterCombinations("23");
    return 0;
}