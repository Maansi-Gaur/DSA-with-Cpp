class Solution {
public:
    int ans = 0;
    int total = 0;
    int m, n;

    void backtrack(vector<vector<int>>& grid, int x, int y, int count) {

        // boundary / obstacle
        if(x < 0 || x >= m || y < 0 || y >= n || grid[x][y] == -1)
            return;

        // ending point
        if(grid[x][y] == 2) {
            if(count == total)
                ans++;

            return;
        }

        // mark visited
        grid[x][y] = -1;

        backtrack(grid, x + 1, y, count + 1);
        backtrack(grid, x - 1, y, count + 1);
        backtrack(grid, x, y + 1, count + 1);
        backtrack(grid, x, y - 1, count + 1);

        // backtrack
        grid[x][y] = 0;
    }

    int uniquePathsIII(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        int sx, sy;

        // count all non-obstacle cells
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                if(grid[i][j] != -1)
                    total++;

                if(grid[i][j] == 1) {
                    sx = i;
                    sy = j;
                }
            }
        }

        backtrack(grid, sx, sy, 1);

        return ans;
    }
};