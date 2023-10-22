class Solution:
    def uniquePaths(self, m: int, n: int) -> int:

        table = [[0 for i in range(n)] for j in range(m)]
        table [0][0] = 1

        for i in range(m):
            for j in range(n):
                if i + 1 < m:
                    table[i + 1][j] += table[i][j]
                if j + 1 < n:
                    table[i][j + 1] += table[i][j]
        
        return table[m - 1][n - 1]

s = Solution()
s.uniquePaths(3, 7)