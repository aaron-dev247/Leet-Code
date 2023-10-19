#include <vector>

using namespace std;

/**
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int profit = 0;

        int left = 0, right = 1;

        while (right < prices.size())
        {
            // right pointer at lowest price
            if (prices[left] > prices[right])
                left = right;
            else
                profit = max(profit, prices[right] - prices[left]);

            right++;
        }

        return profit;
    }
};