#include <string>

using namespace std;

/**
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
class Solution
{
public:
    bool isPalindrome(string s)
    {

        int n = s.length();
        int start = 0, end = n - 1;

        while (start < end)
        {
            while (start < end && !isalnum(s[start]))
                start++;

            while (start < end && !isalnum(s[end]))
                end--;

            if (tolower(s[start]) != tolower(s[end]))
                return false;

            start++;
            end--;
        }

        return true;
    }
};