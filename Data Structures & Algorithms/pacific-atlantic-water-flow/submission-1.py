
class Solution:
    def pacificAtlantic(self, heights: List[List[int]]) -> List[List[int]]:
        if not heights:
            return []
        pacific = set()
        atlantic = set()

        ROWS, COLS = len(heights), len(heights[0])

        def dfs(r, c, visited, prev_height):
                if (r < 0 or c < 0 or r >= ROWS or
                c >= COLS or (r, c) in visited or heights[r][c] < prev_height):
                    return
                
                visited.add((r, c))

                dfs(r + 1, c, visited, heights[r][c])
                dfs(r - 1, c, visited, heights[r][c])
                dfs(r, c + 1, visited, heights[r][c])
                dfs(r, c - 1, visited, heights[r][c]) 

        for c in range(COLS):
            dfs(0, c, pacific, heights[0][c])
        for r in range(ROWS):
            dfs(r, 0, pacific, heights[r][0])    

        for c in range(COLS):
            dfs(ROWS - 1, c, atlantic, heights[ROWS - 1][c])
        for r in range(ROWS):
            dfs(r, COLS - 1, atlantic, heights[r][COLS - 1])            

        res = []
        for r in range(ROWS):
            for c in range(COLS):
                if (r, c) in pacific and (r, c) in atlantic:
                    res.append([r, c])
        
        return res






        









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

---------------------------------------------
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