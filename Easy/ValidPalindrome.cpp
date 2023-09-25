#include <string>

using namespace std;

/**
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */
class Solution
{
public:
    bool isPalindrome(string s)
    {
        string newStr;
        for (char c : s)
        {
            if (isalnum(c))
                newStr += tolower(c);
        }

        int n = newStr.length();
        int start = 0, end = n - 1;

        while (start < end)
        {

            if (newStr[start] != newStr[end])
                return false;

            start++;
            end--;
        }

        return true;
    }
};