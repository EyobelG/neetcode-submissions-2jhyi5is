from collections import deque
class Solution:
    def validTree(self, n: int, edges: List[List[int]]) -> bool:
        # A graph is a valid tree if there are no cycles AND it must be connected
        # Since this is an undirected graph, we can't use Khan's algorithm (or topological sort
        # to identify cycles)
        graph = { i:[] for i in range(n)}
        for u, v in edges:
            graph[u].append(v)
            graph[v].append(u)

        if n == 0:
            return True
        if len(edges) != n - 1:
            return False
        visited = set([0])
        queue = deque([(0, -1)])

        while queue:
            node, parent = queue.popleft()

            for neighbor in graph[node]:
                if neighbor == parent:
                    continue
                
                if neighbor in visited:
                    return False
                
                visited.add(neighbor)
                queue.append((neighbor, node))
        
        return len(visited) == n



"""
"""