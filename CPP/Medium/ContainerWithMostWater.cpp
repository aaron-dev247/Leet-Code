#include <iostream>
#include <vector>

using namespace std;

/**
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int max_area = 0;

        // start from left most and right most indexes
        int left = 0, right = height.size() - 1;
        while (left < right)
        {
            // move the left or right index based on which side is the smallest
            if (height[left] < height[right])
            {
                max_area = max(max_area, height[left] * (right - left));
                left++;
            }
            else
            {
                max_area = max(max_area, height[right] * (right - left));
                right--;
            }
        }
        return max_area;
    }
};

int main()
{
    Solution *s = new Solution();
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << s->maxArea(height);
    return 0;
}