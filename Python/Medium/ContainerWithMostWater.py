class Solution(object):
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        area, base = 0, len(height) - 1
        left, right = 0, base

        while left < right:
            # move left or right pointer depends on which side is smaller
            if (height[left] < height[right]):
                area = max(area, height[left] * base)
                left += 1
            else:
                area = max(area, height[right] * base)
                right -= 1
            base -= 1
        
        return area
    
s = Solution()

s.maxArea([1,8,6,2,5,4,8,3,7])