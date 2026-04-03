class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int minutes = 0;
        int fresh = 0;

        queue<pair<int, int>> q;

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] == 1) {
                    fresh++;
                } else if (grid[r][c] == 2) {
                    q.push({r, c});
                }
            }
        }    
        vector<pair<int, int>> directions = {{0, 1}, {0, -1}, 
        {1, 0}, {-1, 0}};

        while (!q.empty() && fresh > 0) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                pair<int, int> current = q.front();
                q.pop();
                int r = current.first;
                int c = current.second;

                for (auto& dir : directions) {
                    int nr = r + dir.first;
                    int nc = c + dir.second;

                    if (nr >= 0 && nr < rows && nc >= 0 && nc < cols &&
                        grid[nr][nc] == 1) {
                            grid[nr][nc] = 2;
                            q.push({nr, nc});
                            fresh--;
                        }
                }
            }
            minutes++;
        }    
        return (fresh == 0) ? minutes : -1;
    }
};
