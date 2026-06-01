from queue import deque

class Solution:
    def islandsAndTreasure(self, grid: List[List[int]]) -> None:
        if not grid:
            return None

        INF =  (2 ** 31) - 1
        ROWS, COLS = len(grid), len(grid[0])

        visited = set()
        q = deque()

        for r in range(ROWS):
            for c in range(COLS):
                if grid[r][c] == 0:
                    q.append((r, c))
                    visited.add((r, c))

        while q:
            r, c = q.popleft()

            directions =  [[1, 0], [-1, 0], [0, 1], [0, -1]]

            for dr, dc in directions:
                nr, nc = r + dr, c + dc
                
                if (0 <= nr < ROWS
                and 0 <= nc < COLS and 
                (nr, nc) not in visited
                and grid[nr][nc] == INF):

                    grid[nr][nc] = grid[r][c] + 1
                    visited.add((nr, nc))
                    q.append((nr, nc))


                
                



        
    
        






        """
class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        directions = [[1, 0], [-1, 0], [0, 1], [0, -1]]
        ROWS, COLS = len(grid), len(grid[0])
        islands = 0

        def dfs(r, c):
            if (r < 0 or c < 0 or r >= ROWS or
                c >= COLS or grid[r][c] == "0"
            ):
                return

            grid[r][c] = "0"
            for dr, dc in directions:
                dfs(r + dr, c + dc)

        for r in range(ROWS):
            for c in range(COLS):
                if grid[r][c] == "1":
                    dfs(r, c)
                    islands += 1

        return islands
        """