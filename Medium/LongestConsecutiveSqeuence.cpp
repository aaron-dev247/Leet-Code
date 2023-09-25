#include <vector>
#include <unordered_set>

using namespace std;

/**
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */
class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        int longestSequenceCount = 0;

        const int n = nums.size();

        unordered_set<int> uset;
        for (int item : nums)
            uset.insert(item);

        for (int item : uset)
        {
            int length = 0;

            // Find the beginning of a sequence
            if (uset.find(item - 1) == uset.end())
            {
                while (uset.find(item + length) != uset.end())
                    length++;
            }

            longestSequenceCount = max(length, longestSequenceCount);
        }

        return longestSequenceCount;
    }
};
