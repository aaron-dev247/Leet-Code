

from ast import List


class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        answer = [0] * len(temperatures)
        stack = [] # pair: (index, temp)
        for i, t in enumerate(temperatures):
            
            while stack and t > stack[-1][1]:
                stackI = stack.pop()[0]
                answer[stackI] = i - stackI
            
            stack.append((i, t))

        return answer