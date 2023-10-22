from typing import List


class Solution:

    def countComponents(self, n: int, edges: List[List[int]]) -> int:
        
        parents = [i for i in range(n)]
        rank = [1] * n

        def find(n1):
            res = n1

            while res != parents[res]:
                # google this optimization
                parents[res] = parents[parents[res]]
                res = parents[res]
            
            return res
        
        def union(n1, n2):
            p1, p2 = find(n1), find(n2)

            if p1 == p2:
                return 0
            
            # union
            if rank[p2] > rank[p1]:
                parents[p1] = p2
                rank[p2] += rank[p1]
            else:
                parents[p2] = p1
                rank[p1] += rank[p2]
            return 1
        
        res = n
        for n1, n2 in edges:
            res -= union(n1, n2)
        return res
