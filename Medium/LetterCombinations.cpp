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

        unordered_map<char, vector<string>> umap = {
            {'2', {"a", "b", "c"}},
            {'3', {"d", "e", "f"}},
            {'4', {"g", "h", "i"}},
            {'5', {"j", "k", "l"}},
            {'6', {"m", "n", "o"}},
            {'7', {"p", "q", "r", "s"}},
            {'8', {"t", "u", "v"}},
            {'9', {"w", "x", "y", "z"}}};
        int letterShowUpTimes = 1, letterRepeatTimes = 1;
        int n = digits.size();

        for (int i = 1; i < n; i++)
        {
            // calculate how many times a letter will show up in the combinations
            letterShowUpTimes *= umap[digits[i]].size();
        }

        vector<string> letters(umap[digits[0]].size() * letterShowUpTimes, "");

        for (int i = 0; i < n; i++)
        {
            // i indicate string vector at digits[i] in umap
            int numberofLetters = umap[digits[i]].size();
            int letterIndex = 0; // letterIndex indicate string in letters
            for (int x = 0; x < letterRepeatTimes; x++)
            {
                for (int j = 0; j < numberofLetters; j++)
                {
                    string s = umap[digits[i]][j];
                    // j indicate string in umap[digits[i]]'s vector
                    for (int k = 0; k < letterShowUpTimes; k++, letterIndex++)
                    {
                        letters[letterIndex] += s;
                    }
                }
            }

            letterRepeatTimes *= umap[digits[i]].size();
            if (i + 1 < n)
                letterShowUpTimes /= umap[digits[i + 1]].size();
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