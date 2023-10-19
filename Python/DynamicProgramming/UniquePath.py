class Solution:
    def uniquePaths(self, m: int, n: int) -> int:

        memo = {}

        def dfs(m, n):
            if m == 1 and n == 1:
                return 1

            if m == 0 or n == 0:
                return 0
            
            key = (m, n)
            if key in memo:
                return memo[key]

            memo[key] = dfs(m - 1, n) + dfs(m, n - 1)
            return memo[key]

        return dfs(m, n)
