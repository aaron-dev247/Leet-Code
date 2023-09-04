#include <string>
#include <iostream>

using namespace std;

class Solution
{
public:
    string longestPalindrome(string s)
    {
        int index = 0, max_length = 1;
        int n = s.size();
        for (int i = 0; i < n;)
        {
            int start = i, end = i;

            // set end to the last char s[i] that continously appeared
            while (end + 1 < n && s[end] == s[end + 1])
                end++;

            i = end + 1; // start the loop from end (index)

            // search left and right from i (index) until chars are different
            while (start - 1 >= 0 && end + 1 < n && s[start - 1] == s[end + 1])
            {
                start--;
                end++;
            }

            int length = end - start + 1;
            if (length > max_length)
            {
                index = start;
                max_length = length;
            }
        }
        return s.substr(index, max_length);
    }
};

int main()
{
    Solution *s = new Solution();
    cout << s->longestPalindrome("abacab");
    return 0;
}