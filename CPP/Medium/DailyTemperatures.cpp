#include <vector>
#include <utility>

using namespace std;

/**
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */
class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        int n = temperatures.size();
        vector<int> answer(n, 0);
        vector<pair<int, int>> stack;

        for (int i = 0; i < n; i++)
        {
            while (!empty(stack) && stack.back().second < temperatures[i])
            {
                answer[stack.back().first] = i - stack.back().first;
                stack.pop_back();
            }
            stack.push_back(make_pair(i, temperatures[i]));
        }

        return answer;
    }
};

int main()
{
    Solution *s = new Solution();
    vector<int> temp = {73, 74, 75, 71, 69, 72, 76, 73};
    s->dailyTemperatures(temp);
}