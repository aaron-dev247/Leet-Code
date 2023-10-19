#include <vector>
#include <string>
#include <unordered_map>
#include <functional>

using namespace std;

/**
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        unordered_map<string, function<int(int, int)>> operators = {
            {"+", [](const int &a, const int &b) -> int
             { return b + a; }},
            {"-", [](const int &a, const int &b) -> int
             { return b - a; }},
            {"*", [](const int &a, const int &b) -> int
             { return b * a; }},
            {"/", [](const int &a, const int &b) -> int
             { return b / a; }}};
        vector<int> numStack;

        for (string s : tokens)
        {
            if (operators.find(s) == operators.end())
            {
                numStack.push_back(stoi(s));
                continue;
            }
            const int a = numStack.back();
            numStack.pop_back();
            const int b = numStack.back();
            numStack.pop_back();
            numStack.push_back(operators[s](a, b));
        }
        return numStack[0];
    }
};