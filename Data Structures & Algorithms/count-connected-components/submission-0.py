class Solution:
    def countComponents(self, n: int, edges: List[List[int]]) -> int:
        graph = { i:[] for i in range(n)}

        for u, v in edges:
            graph[u].append(v)
            graph[v].append(u)

        visited = set()
        comp_count = 0

        def dfs(node):
            visited.add(node)

            for neighbor in graph[node]:
                if neighbor not in visited:
                    dfs(neighbor)
        
        for node in range(n):
            if node not in visited:
                comp_count += 1
                dfs(node)
        return comp_count
            






"""

from collections import deque
class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        preMap = { i:[] for i in range(numCourses)}

        for crs, pre in prerequisites:
            preMap[crs].append(pre)
        
        res = []
        visitSet = set()
        cycleSet = set()
        
        def dfs(crs):
            if crs in visitSet:
                return False
            if crs in cycleSet:
                return True
            visitSet.add(crs)

            for pre in preMap[crs]:
                if not dfs(pre):
                    return False
            visitSet.remove(crs)
            cycleSet.add(crs)
            res.append(crs)
            return True
        for crs in range(numCourses):
            if not dfs(crs):
                return []
        return res
        

"""