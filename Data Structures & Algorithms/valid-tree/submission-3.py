from collections import deque
class Solution:
    def validTree(self, n: int, edges: List[List[int]]) -> bool:
        # A graph is a valid tree if there are no cycles AND it must be connected
        # Since this is an undirected graph, we can't use Khan's algorithm (or topological sort
        # to identify cycles)
        if n == 0:
            return True
        if len(edges) != n - 1:
            return False
        graph = { i:[] for i in range(n)}

        for u, v in edges:
            graph[u].append(v)
            graph[v].append(u)
        
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
from queue import deque

class Solution:
    def islandsAndTreasure(self, grid: List[List[int]]) -> None:
        if not grid:
            return None
        
        INF = (2 ** 31) - 1
        q = deque()
        visited = set()

        ROWS, COLS = len(grid), len(grid[0])
        for r in range(ROWS):
            for c in range(COLS):
                if grid[r][c] == 0:
                    q.append((r, c))
                    visited.add((r, c))
        while q:
            r, c = q.popleft()
            directions = [[1, 0], [-1, 0], [0, 1], [0, -1]]
            for dr, dc in directions:
                nr, nc = r + dr, c + dc
                if (0 <= nr < ROWS and
                    0 <= nc < COLS and
                    (nr, nc) not in visited
                    and grid[nr][nc] == INF):
                        grid[nr][nc] = 1 + grid[r][c]
                        q.append((nr, nc))
                        visited.add((nr, nc))  
"""