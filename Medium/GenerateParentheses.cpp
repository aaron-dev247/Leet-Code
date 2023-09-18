#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> strs;
        this->recurse(strs, 0, 0, "", n);
        return strs;
    }

private:
    void recurse(vector<string> &strs, int left, int right, string s, int n)
    {
        if (s.length() == n * 2) // n complete parentheses in string s
        {
            strs.push_back(s);
            return;
        }

        if (left < n)
        {
            recurse(strs, left + 1, right, s + '(', n);
        }

        if (right < left)
        {
            recurse(strs, left, right + 1, s + ')', n);
        }
    }
};

int main()
{
    Solution *s = new Solution();
    s->generateParenthesis(3);
    return 0;
}