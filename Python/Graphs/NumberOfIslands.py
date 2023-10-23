from typing import List


class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        visited = set()
        count = 0

        def dfs(r, c):
            
            # prevent out of bound
            rowInbounds = 0 <= r and r < len(grid)
            colInbounds = 0 <= c and c < len(grid[0])
            
            if not rowInbounds or not colInbounds:
                return False

            # prevent infinite loop
            if (r, c) in visited or grid[r][c] == '0':
                return False
            
            visited.add((r, c))
            
            dfs(r - 1, c)
            dfs(r + 1, c)
            dfs(r, c - 1)
            dfs(r, c + 1)

            return True
        
        for r in range(len(grid)):
            for c in range(len(grid[0])):
                
                if dfs(r, c):
                    count += 1
        
        return count

s = Solution()
s.numIslands([
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
])