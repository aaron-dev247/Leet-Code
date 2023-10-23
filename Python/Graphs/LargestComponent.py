from typing import List


class Solution:
    def largestComponent(self, graph: dict[List[int]]) -> int:
        visited = set()
        largestCount = 0

        def dfs(cur):

            if cur in visited:
                return 0
            visited.add(cur)

            total = 1
            for neighbor in graph[cur]:
                total += dfs(neighbor)
            return total
        
        for node in graph:
            largestCount = max(largestCount, dfs(node))
        
        return largestCount

s = Solution()
print(s.largestComponent({
  0: [8, 1, 5],
  1: [0],
  5: [0, 8],
  8: [0, 5],
  2: [3, 4],
  3: [2, 4],
  4: [3, 2]
}))