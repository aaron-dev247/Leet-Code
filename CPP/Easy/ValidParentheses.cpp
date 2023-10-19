#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> st;
        for (char c : s)
        {
            if (c == '(' || c == '{' || c == '[')
                st.push(c); // push all open brackets into stack
            else            // close brackets
            {
                if (st.empty()) // close bracket at start
                    return false;

                if (c == ')' && st.top() != '(' ||
                    c == '}' && st.top() != '{' ||
                    c == ']' && st.top() != '[') // no matching open bracket
                    return false;
                st.pop();
            }
        }
        return st.empty();
    }
};

int main()
{
    Solution *s = new Solution();
    cout << s->isValid("(())()");
    return 0;
}