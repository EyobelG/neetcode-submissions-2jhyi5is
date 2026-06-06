class Solution:
    def findRedundantConnection(self, edges: List[List[int]]) -> List[int]:
        graph = {i: [] for i in range(1, len(edges) + 1)}

        n = len(edges)
        parent = list(range(n + 1))

        def find(u):
            if (parent[u] != u):
                parent[u] = find(parent[u])
            
            return parent[u]

        def union(u, v) -> bool:
            urep = find(u)

            vrep = find(v)

            if urep == vrep:
                return False

            parent[urep] = vrep
            return True

        for u, v in edges:
            if (union(u, v) == False):
                return [u, v]
        return None         



                


"""

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
