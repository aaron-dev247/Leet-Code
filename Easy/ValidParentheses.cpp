#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        unordered_map<char, char> umap = {
            {'(', ')'},
            {'{', '}'},
            {'[', ']'}};
        int i = 0;
        string str = s;
        while (i < str.length())
        {
            if (umap.find(str[i]) == umap.end()) // not open bracket
                return false;

            size_t found = str.find(umap[str[i]], i);
            if (found == string::npos) // same type of bracket not found
                return false;

            if (found == i + 1)
            {
                // remove the matching parenthese from str
                str = str.substr(0, i) + str.substr(i + 2);
                i = 0;
            }
            else
            {
                i++;
            }
        }
        return true;
    }
};

int main()
{
    Solution *s = new Solution();
    cout << s->isValid("(())()");
    return 0;
}