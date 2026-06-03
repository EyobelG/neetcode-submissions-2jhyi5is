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

        # Use topological sort
from collections import deque
class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        preMap = { i:[] for i in range(numCourses)}

        for crs, pre in prerequisites:
            preMap[crs].append(pre)

        visitSet = set()

        def dfs(crs):
            if crs in visitSet:
                return False
            if preMap[crs] == []:
                return True
            
            visitSet.add(crs)

            for pre in preMap[crs]:
                if not dfs(pre):
                    return False
            
            visitSet.remove(crs)

            preMap[crs] = []
            return True

        for crs in range(numCourses):
            if not dfs(crs):
                return False
        return True
        """