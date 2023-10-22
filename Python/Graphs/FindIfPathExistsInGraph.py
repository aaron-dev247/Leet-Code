from collections import deque
from typing import List


class Solution:

    def validPath(self, n: int, edges: List[List[int]], source: int, destination: int) -> bool:
        graph = self.buildGraph(edges)
        visited = set()
        queue = deque([source])

        while queue:
            node = queue.popleft()

            if node == destination:
                return True
            
            if node in visited:
                continue
            visited.add(node)
            
            for neighbor in graph[node]:
                queue.append(neighbor)
            
        return False
    
    def buildGraph(self, edges):
        graph = {}

        for edge in edges:
            a, b = edge
            
            if a not in graph:
                graph[a] = []
            
            if b not in graph:
                graph[b] = []

            graph[a].append(b)
            graph[b].append(a)
        
        return graph
