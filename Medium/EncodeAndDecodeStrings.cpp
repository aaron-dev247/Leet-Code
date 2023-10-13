#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    string encode(vector<string> &strs)
    {
        string res;
        for (string s : strs)
        {
            res += to_string(s.length()) + '#' + s;
        }
        return res;
    }

    vector<string> decode(string &str)
    {
        vector<string> res;

        int i = 0;

        while (i < str.size())
        {
            size_t found = str.find('#', i);
            str.substr(i, found - i);
        }

        return res;
    }
};