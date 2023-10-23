from typing import List
from collections import deque


class Solution:

    def sortestPath(self, edges: List[List[int]], nodeA, nodeB):

        graph = self.buildGraph(edges)
        visited = set([nodeA])
        queue = deque([(nodeA, 0)])
        
        while queue:
            node, dest = queue.popleft()

            if node == nodeB:
                return dest
            
            for neighbor in graph[node]:

                if neighbor in visited:
                    continue
                
                visited.add(neighbor)
                queue.append((neighbor, dest + 1))
        
        return -1

    
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